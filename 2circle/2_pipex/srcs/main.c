#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	args;
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		error_handler("Pipex: Invalid argument");
	set_arg(argv, envp, &args);
	pipe(fd);
	pid = fork();
	pipex(&args, fd, envp, &pid);
	return (0);
}