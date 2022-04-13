#include "pipex.h"

void	all_free(t_arg *args, char *msg, int flag)
{
	if (flag)
	{
		double_free(args->cmd, 0, 0);
		free(args->path);
	}
	if (args->infile)
		free(args->infile);
	else
		free(args->limiter);
	free(args->outfile);
	error_handler(msg);
}

void	single_free(char *src, char *msg)
{
	free(src);
	error_handler(msg);
}

void	double_free(char **src1, char **src2, char *msg)
{
	int	i;

	i = 0;
	while (src1[i])
	{
		free(src1[i]);
		i++;
	}
	free(src1);
	i = 0;
	if (src2)
	{
		while (src2[i])
		{
			free(src2[i]);
			i++;
		}
		free(src2);
	}
	if (!msg)
		return ;
	error_handler(msg);
}

void	error_handler(char *msg)
{
	perror(msg);
	exit(1);
}
