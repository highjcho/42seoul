/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:12:49 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/19 09:12:52 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_here_doc(int *argc, char **argv, t_arg *args)
{
	int	in_fd;
	int	dup_ret;
	int	i;

	i = 1;
	while (++i < (*argc) + 1)
		argv[i - 1] = argv[i];
	args->here_doc = TRUE;
	(*argc)--;
	args->limiter = ft_strdup(argv[1]);
	if (!args->limiter)
		error_handler("pipex: allocate failed", 1);
	args->infile = ft_strdup("tmp");
	if (!args->infile)
		single_free(args->limiter, 0, "pipex: allocate failed");
			in_fd = open(args->infile, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (in_fd < 0)
		single_free(args->limiter, args->infile, "pipex: file open failed");
	dup_ret = dup2(in_fd, 1);
	if (dup_ret < 0)
		single_free(args->limiter, args->infile, "pipex: file dup failed");
	close(in_fd);
}

static void	write_here_doc(t_arg *args)
{
	char	here_doc[4097];
	int		len;
	int		rd;

	len = ft_strlen(args->limiter);
	while (1)
	{
		rd = read(0, here_doc, 4096);
		if (rd < 0)
			single_free(args->limiter, args->infile, "pipex: read failed");
		here_doc[rd] = 0;
		if (rd == len + 1 && !(ft_strncmp(args->limiter, here_doc, len)))
			break ;
		write(1, here_doc, rd);
	}
	free(args->limiter);
	args->limiter = NULL;
}

static void	set_arg(int argc, char **argv, t_arg *args)
{
	if (args->here_doc == TRUE)
		write_here_doc(args);
	else
	{
		args->infile = ft_strdup(argv[1]);
		if (!args->infile)
			error_handler("pipex: allocate failed", 1);
	}
	args->outfile = ft_strdup(argv[argc - 1]);
	if (!args->outfile)
		single_free(args->infile, 0, "pipex: allocate failed");
	args->cnt = argc - 3;
	args->cmd = NULL;
	args->path = NULL;
	args->flag = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	args;

	if (argc < 5)
	{
		write(1, "pipex: too few arguments", 23);
		return (0);
	}
	if (!ft_strncmp(argv[1], "here_doc", 9))
		set_here_doc(&argc, argv, &args);
	else
	{
		args.here_doc = FALSE;
		args.limiter = NULL;
	}
	set_arg(argc, argv, &args);
	multi_pipex(&args, argv, envp);
	all_free(&args, 0, 0);
	return (0);
}
