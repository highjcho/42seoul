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

void	set_path(t_arg *args, char **envp)
{
	int		i;
	int	j;

	i = -1;
	j = -1;
	args->path = NULL;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			args->path = ft_split(envp[i] + 5, ':');
			if (!args->path)
				error_handler("pipex: allocate failed", errno);
			return ;
		}
	}
	if (!args->path)
		error_handler("pipex: wrong path", 1);
}

static int	check_cmd(t_arg *args)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strjoin("/", args->cmd[0]);
	while (args->path[++i])
	{
		args->cmd_path = ft_strjoin(args->path[i], tmp);
		if (!access(args->cmd_path, F_OK) && !access(args->cmd_path, X_OK))
		{
			free(tmp);
			return (TRUE);
		}
		else
			free(args->cmd_path);
	}
	args->cmd_path = tmp;
	return (FALSE);
}

void	set_cmd(t_arg *args, char *cmd)
{
	args->cmd = ft_split(cmd, ' ');
	if (!args->cmd)
		error_handler("pipex: allocate failed", errno);
	if (args->cmd[0][0] == '/')
	{
		args->cmd_path = ft_strdup(args->cmd[0]);
		if (!args->path)
			double_free(args->cmd, "allocate failed", errno);
		if (access(args->cmd[0], F_OK) < 0 || access(args->cmd[0], X_OK) < 0)
			args->cmd_err = TRUE;
		return ;
	}
	if (!check_cmd(args))
		args->cmd_err = TRUE;
}
