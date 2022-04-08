#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"


typedef struct	s_arg
{
	int		in_fd;
	int		out_fd;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_arg;

void	set_arg(char **argv, char **envp, t_arg *args);
void	cmd_free(char **cmd1, char **cmd2);
void	error_handler(char *msg);

#endif