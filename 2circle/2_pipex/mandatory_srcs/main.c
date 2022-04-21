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

static void	set_input(t_arg *args, char *infile)
{
	int	in_fd;
	int	dup_ret;

	in_fd = open(infile, O_RDONLY);
	if (in_fd < 0)
		error_handler("pipex: file open failed", errno);
	dup_ret = dup2(in_fd, 0);
	close(in_fd);
	dup_ret = 0;
	if (dup_ret < 0)
		error_handler("pipex: file dup failed", errno);
	args->path = NULL;
	args->cmd = NULL;
	args->cmd_path = NULL;
	args->cmd_err = FALSE;
}

static void	write_here_doc(char *limiter)
{
	char	*here_doc;
	int		tmp;
	size_t	lim_len;
	size_t	doc_len;
	int		dup_ret;

	lim_len = ft_strlen(limiter);
	tmp = open("tmp", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (tmp < 0)
		error_handler("pipex: file open failed", errno);
	dup_ret = dup2(tmp, STDOUT_FILENO);
	if (dup_ret < 0)
		error_handler("pipex: file dup failed", errno);
	close(tmp);
	here_doc = get_next_line(STDIN_FILENO);
	while (here_doc)
	{
		doc_len = ft_strlen(here_doc);
		if (doc_len == lim_len + 1 && !(ft_strncmp(limiter, here_doc, lim_len)))
			return ;
		write(1, here_doc, doc_len);
		free(here_doc);
		here_doc = get_next_line(STDIN_FILENO);
	}
	error_handler("read failed", errno);
}

static void	set_here_doc(int *argc, char **argv, t_arg *args)
{
	int	i;

	if (*argc < 6)
		error_handler("pipex: too few options", EXIT_FAILURE);
	i = 1;
	while (++i < *argc)
		argv[i - 1] = argv[i];
	(*argc)--;
	args->here_doc = TRUE;
	write_here_doc(argv[1]);
	set_input(args, "tmp");
}

static void	set_non_here_doc(char *infile, t_arg *args)
{
	args->here_doc = FALSE;
	set_input(args, infile);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	args;
	int		read_fd;
	int		i;

	if (argc < 5)
		error_handler("pipex: too few options", EXIT_FAILURE);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		set_here_doc(&argc, argv, &args);
	else
		set_non_here_doc(argv[1], &args);
	set_path(&args, envp);
	i = 1;
	read_fd = STDIN_FILENO;
	while (i++ < argc - 3)
	{
		set_cmd(&args, argv[i]);
		read_fd = pipex(&args, envp, read_fd);
		cmd_free(&args, 0, 0);
	}
	set_cmd(&args, argv[i]);
	output(&args, argv[argc - 1], envp, read_fd);
	all_free(&args, 0, 0);
	return (0);
}
