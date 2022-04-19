/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:12:09 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/19 09:12:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child_p(t_arg *args, char **envp, int i)
{
	if (i == 0)
		redirect_in(args);
	else if (i + 1 == args->cnt)
		redirect_out(args, i);
	else
	{
		if (i % 2)
		{
			direct_pipe(args, args->fd1, 0);
			direct_pipe(args, args->fd2, 1);
		}
		else
		{
			direct_pipe(args, args->fd2, 0);
			direct_pipe(args, args->fd1, 1);
		}
	}
	if (args->flag == 1)
		args->flag = 0;
	if (execve(args->path, args->cmd, envp) > 0)
		all_free(args, "pipex: execute failed", 1);
}

static void	parent_p(t_arg *args, pid_t *pid, int i)
{
	int	status;

	waitpid(*pid, &status, WNOHANG);
	if (i == 0)
		close(args->fd1[1]);
	else if (i + 1 == args->cnt && i % 2)
		close(args->fd2[1]);
	else if (i + 1 == args->cnt && !(i % 2))
		close(args->fd1[1]);
	else
	{
		if (i % 2)
		{
			close(args->fd1[0]);
			close(args->fd2[1]);
		}
		else
		{
			close(args->fd2[0]);
			close(args->fd1[1]);
		}
	}
}

static void	pipex(t_arg *args, char **envp, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		all_free(args, "pipex: fork failed", 1);
	else if (pid == 0)
		child_p(args, envp, i);
	else
		parent_p(args, &pid, i);
}

void	multi_pipex(t_arg *args, char **argv, char **envp)
{
	int	*fd;
	int	i;

	i = -1;
	while (++i < args->cnt)
	{
		if (args->cmd && args->path)
		{
			free(args->path);
			double_free(args->cmd, 0, 0);
		}
		set_cmd(argv, envp, args, i);
		fd = args->fd1;
		if (i % 2)
			fd = args->fd2;
		if (pipe(fd) < 0)
			all_free(args, "pipex: pipe failed", 1);
		pipex(args, envp, i);
	}
	if (args->here_doc == TRUE)
		unlink(args->infile);
	if (args->flag == 1)
	{
		all_free(args, "pipex: command not found", errno);
		args->flag = 0;
	}
}
