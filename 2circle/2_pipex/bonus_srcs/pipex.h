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
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_arg;

void	pipex(t_arg *args, int *fd, char **envp, pid_t *pid);
void	set_arg(char **argv, char **envp, t_arg *args);
void	single_free(char *src, char *msg);
void	double_free(char **free1, char **free2, char *msg);
void	all_free(t_arg *args, char *msg);
void	error_handler(char *msg);

#endif