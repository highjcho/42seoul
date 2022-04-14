#include "pipex.h"

static void	redirect_in(t_arg *args)
{
	int	in_fd;
	int	dup_ret;
	
	in_fd = open(args->first, O_RDONLY);
	if (in_fd < 0)
		all_free(args, "Pipex: 111File open failed.", 0);
	dup_ret = dup2(in_fd, STDIN_FILENO);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.", 0);
}

static void	redirect_out(t_arg *args)
{
	int	out_fd;
	int	dup_ret;

	out_fd = open(args->outfile, O_RDWR | O_CREAT | O_APPEND, 0644); // append가 맞는지..??????????
	if (out_fd < 0)
		all_free(args, "Pipex: out File open failed.", 0);
	dup_ret = dup2(out_fd, STDOUT_FILENO);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.", 0);
}

static void	direct_pipe(t_arg *args, int *fd, int use_fd, int close_fd)
{
	int	dup_ret;

	dup_ret = dup2(fd[use_fd], use_fd);
	if (dup_ret < 0)
		all_free(args, "Pipex: File dup failed.", 0);
	close(fd[close_fd]);
}

void	child_p(t_arg *args, int fd[2][2], char **envp, int i)
{
	direct_pipe(args, fd[0], 0, 1);
	direct_pipe(args, fd[1], 1, 0);
	if (execve(args->path, args->cmd, envp) > 0)
		all_free(args, "Pipex: Execute failed.", 0);
}

void	parent_p(t_arg *args, int fd[2][2], pid_t *pid, int i)
{
	wait(pid);
	direct_pipe(args, fd[1], 0, 1);
	if (i + 1 < args->cnt)
		return;
	direct_pipe(args, fd[0], 1, 0); 
}


void	pipex(t_arg *args, int fd[2][2], char **envp, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		all_free(args, "Pipex: Fork error.", 0);
	else if (pid == 0)
		child_p(args, fd, envp, i);
	else
		parent_p(args, fd, &pid, i);

}

void	multi_pipex(t_arg *args, char **argv, char **envp)
{
	int	fd[2][2];
	int	i;
	char buf[10000];
	int	rd;

	if (pipe(fd[0]) < 0)
		all_free(args, "Pipex: Pipe error.", 0);
	if (args->here_doc == FALSE)
	{
		redirect_in(args);
		direct_pipe(args, fd[0], 1, 0);
		rd = read(0, buf, 10000);
		write(1, buf, rd);
	}
	i = -1;
//	while (++i < args->cnt)
//	{
		if (pipe(fd[1]) < 0)
			all_free(args, "Pipex: pipe error.", 0);
		set_cmd(argv, envp, args, i);
		pipex(args, fd, envp, i);
//	}
	redirect_out(args);
	all_free(args, 0, 1); // 구조체 다 프리해주기 // 파이프는 어떻게 닫아줘
}