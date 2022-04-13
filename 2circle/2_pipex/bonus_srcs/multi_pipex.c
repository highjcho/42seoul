#include "pipex.h"

static void	redirect_in(t_arg *args)
{
	int	in_fd;
	int	dup_ret;
	
	in_fd = open(args->infile, O_RDONLY);
	if (in_fd < 0)
		all_free(args, "Pipex: File open failed.", 0);
	dup_ret = dup2(in_fd, STDIN_FILENO);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.", 0);
	close(in_fd);
}

static void	redirect_out(t_arg *args)
{
	int	out_fd;
	int	dup_ret;

	out_fd = open(args->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		all_free(args, "Pipex: File open failed.", 0);
	dup_ret = dup2(out_fd, STDOUT_FILENO);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.", 0);
	close(out_fd);
}

static void	direct_pipe(t_arg *args, int *fd, int use_fd, int close_fd)
{
	int	dup_ret;

	dup_ret = dup2(fd[use_fd], use_fd);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.", 0);
	close(fd[close_fd]);
}

static void	direct_pipe(t_arg *args, int *fd, int use_fd, int close_fd)
{
	int	dup_ret;

	dup_ret = dup2(fd[args->in_fd][use_fd], fd[args->out_fd][use_fd]); // 이런 느낌으로 돼야 겠는데; in_fd/out_fd가 바뀌어야 하는 지 아닌지 모르겠음
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.", 0);
	close(fd[close_fd]);
}

void	child_p(t_arg *args, int **fd, int i)
{
	if (i == 0) // 처음이고 
	{
		if (args->here_doc == FALSE) // 표준입력으로 받을 게 아니면
			redirect_in(args);							// infile 읽고
		direct_pipe(args, fd[args->in_fd], 1, 0);  // pipe에 출력
		// execve 해야함
	}
	else if (i != 0) // 중간이고
	{
		direct_pipe(args, fd[args->in_fd], 0, 1); // in_fd에 이부분 다시 짜야겠는걸..... ㅠ fd_in[0], fd_out[0]
		direct_pipe(args, fd[args->out_fd], 0, 1); // close가 그게 되는 게 맞는지...
		// execve 해야함
	}
	if (i != args->cnt - 1) // -1이 맞나,,? 최종은 다이렉트파이프로 읽고 
	{
		direct_pipe(args, fd[args->])
		redirect_out
	}

}


void	pipex(t_arg *args, int **fd, char **envp, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		all_free(args, "Pipex: Fork error.", 0);
	else if (pid == 0)
		child_p(args, fd, i);
	else
		parent_p();

}

void	multi_pipex(t_arg *args, char **envp)
{
	int		fd[2][2];
	int		i;

	i = -1;
	while (++i < args->cnt)
	{
		if (!(i % 2))
		{
			if (pipe(fd[0]) < 0)
				all_free(args, "Pipex: Pipe error.", 0);
			args->in_fd = 0;
			args->out_fd = 1;
		}
		else
		{
			if (pipe(fd[1]) < 0)
				all_free(args, "Pipex: Pipe error.", 0);
			args->in_fd = 1;
			args->out_fd = 0;
		}
		pipex(args, fd, envp, i);
	}
}