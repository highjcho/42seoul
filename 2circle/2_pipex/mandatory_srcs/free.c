#include "pipex.h"

void	single_free(char *src1, char *src2, char *msg)
{
	free(src1);
	if (src2)
		free(src2);
	error_handler(msg);
}

void	double_free(char **src, char *msg)
{
	int	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
	if (!msg)
		return ;
	error_handler(msg);
}

void	all_free(t_arg *args, char *msg)
{
	free(args->infile);
	free(args->outfile);
	free(args->path);
	double_free(args->cmd, msg);
}

void	error_handler(char *msg)
{
	perror(msg);
	exit(1);
}
