/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:12:12 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/19 09:12:13 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*check_cmd(char **path, char *cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strjoin("/", cmd);
	while (path[++i])
	{
		cmd_path = ft_strjoin(path[i], tmp);
		if (!access(cmd_path, F_OK) && !access(cmd_path, X_OK))
		{
			free(tmp);
			return (cmd_path);
		}
		else
			free(cmd_path);
	}
	return (NULL);
}

static void	set_path(char **envp, t_arg *args)
{
	char	**path;
	int		i;

	path = 0;
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_split(envp[i] + 5, ':');
			break ;
		}
	}
	if (!path)
		single_free(args->infile, args->outfile, "pipex: allocate failed");
	args->path = check_cmd(path, args->cmd[0]);
	if (!args->path)
		args->flag = 1;
	double_free(path, 0, 0);
}

void	set_cmd(char **argv, char **envp, t_arg *args, int i)
{
	args->cmd = ft_split(argv[i + 2], ' ');
	if (!args->cmd)
		single_free(args->infile, args->outfile, "pipex: allocate failed");
	if (args->cmd[0][0] == '/')
	{
		if (!access(args->cmd[0], F_OK) && !access(args->cmd[0], X_OK))
		{
			args->path = ft_strdup(args->cmd[0]);
			if (!args->path)
				single_free(args->infile, args->outfile, \
				"pipex: allocate failed");
			return ;
		}
		else
		{
			args->flag = 1;
			return ;
		}
	}
	set_path(envp, args);
}
