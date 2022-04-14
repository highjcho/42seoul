#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0


typedef struct	s_arg
{
	char	*first;
	char	*outfile;
	char	**cmd;
	char	*path;
	int		here_doc;
	int		cnt;
	int		in_fd;
	int		out_fd;
}	t_arg;

void	multi_pipex(t_arg *args, char **argv, char **envp);
void	set_cmd(char **argv, char **envp, t_arg *args, int i);
void	single_free(char *src, char *msg);
void	double_free(char **free1, char **free2, char *msg);
void	all_free(t_arg *args, char *msg, int flag);
void	error_handler(char *msg);

#endif