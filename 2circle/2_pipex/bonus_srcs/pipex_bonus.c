/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:52:38 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/21 10:52:58 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	dup_fd(t_arg *args, int from_fd, int to_fd)
{
	int	dup_ret;

	dup_ret = dup2(from_fd, to_fd);
	if (dup_ret < 0)
		all_free(args, "pipex: file dup failed", errno);
}

int	pipex(t_arg *args, char **envp, int read_fd)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		status;

	if (pipe(pipe_fd) < 0)
		all_free(args, "pipex: pipe failed", errno);
	pid = fork();
	if (pid < 0)
		all_free(args, "pipex: fork failed", errno);
	if (pid == 0)
	{
		printf("read: %d, pipe_in: %d\n", read_fd, pipe_fd[0]);
		close(pipe_fd[0]);
		dup_fd(args, read_fd, STDIN_FILENO);
		dup_fd(args, pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		if (execve(args->cmd_path, args->cmd, envp) < 0)
		{
			if (args->cmd_err == FALSE)
				all_free(args, "pipex: execve failed", errno);
			all_free(args, "pipex: command not found", errno);
		}
	}
	close(pipe_fd[1]);
	waitpid(pid, &status, WNOHANG);
	return (pipe_fd[0]);
}

static void	set_out_file(t_arg *args, char *outfile)
{
	int	out_fd;

	if (args->here_doc == TRUE)
	{
		out_fd = open(outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
		unlink("tmp");
	}
	else
		out_fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		all_free(args, "pipex: file open failed", errno);
	dup_fd(args, out_fd, STDOUT_FILENO);
	close(out_fd);
}

void	output(t_arg *args, char *outfile, char **envp, int read_fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		all_free(args, "pipex: fork failed", errno);
	if (pid == 0)
	{
		dup_fd(args, read_fd, STDIN_FILENO);
		close(read_fd);
		set_out_file(args, outfile);
		if (execve(args->cmd_path, args->cmd, envp) < 0)
		{
			if (args->cmd_err == FALSE)
				all_free(args, "pipex: execve failed", errno);
			all_free(args, "pipex: command not found", errno);
		}
	}
	else
		waitpid(pid, &status, WNOHANG);
}
