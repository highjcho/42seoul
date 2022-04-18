#include "pipex.h"

void	direct_pipe(t_arg *args, int *fd, int use_fd)
{
	int	dup_ret;

	dup_ret = dup2(fd[use_fd], use_fd);
	close(fd[use_fd]);
	if (dup_ret < 0)
		all_free(args, "pipex: File dup failed");
}

void	redirect_in(t_arg *args)
{
	int		in_fd;
	int		dup_ret;
	
	in_fd = open(args->infile, O_RDONLY);
	if (in_fd < 0)
		all_free(args, "pipex: file open failed");
	dup_ret = dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	if (dup_ret < 0)
		all_free(args, "pipex: file dup failed");
	close(args->fd1[0]);
	direct_pipe(args, args->fd1, 1);
}

void	redirect_out(t_arg *args, int i)
{
	int	out_fd;
	int	dup_ret;

	if (i % 2)
	{
		close(args->fd1[1]);
		direct_pipe(args, args->fd1, 0);
	}
	else
	{
		close(args->fd2[1]);
		direct_pipe(args, args->fd2, 0);
	}
	if (args->here_doc == TRUE)
		out_fd = open(args->outfile, O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		out_fd = open(args->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		all_free(args, "pipex: outfile open failed");
	dup_ret = dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	if (dup_ret < 0)
		all_free(args, "pipex: file dup failed");
}