#include "pipex.h"

void	cmd_free(char **cmd1, char **cmd2)
{
	int	i;

	i = 0;
	while (cmd1[i])
	{
		free(cmd1[i]);
		i++;
	}
	free(cmd1);
	i = 0;
	if (cmd2)
	{
		while (cmd2[i])
		{
			free(cmd2[i]);
			i++;
		}
		free(cmd2);
	}
}

void	error_handler(char *msg)
{
	perror(msg);
	exit(1);
}
