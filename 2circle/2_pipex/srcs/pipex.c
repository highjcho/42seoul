#include "pipex.h"

static void	redirect_in(t_arg *args)
{
	int	in_fd;
	int	dup_ret;
	
	in_fd = open(args->infile, O_RDONLY);
	if (in_fd < 0)
		all_free(args, "Pipex: File open failed.");
	dup_ret = dup2(in_fd, STDIN_FILENO);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.");
	//close 필요 함;;?
}

static void	redirect_out(t_arg *args)
{
	int	out_fd;
	int	dup_ret;

	out_fd = open(args->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644); // open(outfile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (out_fd < 0)
		all_free(args, "Pipex: File open failed.");
	dup_ret = dup2(out_fd, STDOUT_FILENO);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.");
}

static void	direct_pipe(t_arg *args, int *fd, int use_fd, int close_fd)
{
	int	dup_ret;

	dup_ret = dup2(fd[use_fd], use_fd);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.");
	close(fd[close_fd]);
}

void	pipex(t_arg *args, int *fd, char **envp, pid_t *pid)
{
	if (*pid == 0)
	{
		redirect_in(args);
		direct_pipe(args, fd, 1, 0);
		if (execve(args->cmd1_path, args->cmd1, envp) > 0)
			all_free(args, "Pipex: Execute failed.");
	}
	else
	{
		wait(pid);
		direct_pipe(args, fd, 0, 1);
		redirect_out(args);
		if (execve(args->cmd2_path, args->cmd2, envp) > 0)
			all_free(args, "Pipex: Execute failed.");
	}
}