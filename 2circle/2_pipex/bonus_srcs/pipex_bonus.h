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
	char	*limiter;
	char	*infile;
	char	*outfile;
	char	**cmd;
	char	*path;
	int		here_doc;
	int		cnt;
	int		fd1[2];
	int		fd2[2];
}	t_arg;

void	multi_pipex(t_arg *args, char **argv, char **envp);
void	set_cmd(char **argv, char **envp, t_arg *args, int i);
void	direct_pipe(t_arg *args, int *fd, int use_fd);
void	redirect_in(t_arg *args);
void	redirect_out(t_arg *args, int i);
void	single_free(char *src1, char *src2, char *msg);
void	double_free(char **cmd, char *msg);
void	all_free(t_arg *args, char *msg);
void	error_handler(char *msg);

#endif