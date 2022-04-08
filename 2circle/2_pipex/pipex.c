#include "pipex.h"

//./pipex infile "ls -l" "wc -l" outfile


int	main(int argc, char **argv, char **envp)
{
	t_arg	args;
	int		fd[2];
	pid_t	pid;

	if (argc < 5 || argc > 5)
		error_handler("Pipex: Invalid argument");
	set_arg(argv, envp, &args); // 여기서 인자 파싱 끝인가????
	// pipe(fd);
	// pid = fork();
	// if (pid == 0)
	// {
	// 	close(fd[0]);
	// 	dup2(fd[1], 1);
	// 	execve(args->cmd1_path, args->cmd1[1], 0);
	// 	error_free();// execve로 빠져나가지 못하면 여기서 실행 종료 시켜 버리긔 perror 나 strerror는 언제 하는거냐 이런 때 써야하나..
	// }
	// else
	// {
	// 	wait(pid); // 자식이 파이프로 보내줄 때 까지 기다려
	// 	close(fd[1]);
	// 	dup2(fd[0], args->in_fd);
	// 	execve(args->cmd2_path, args->cmd2[1], 0);
	// }
}