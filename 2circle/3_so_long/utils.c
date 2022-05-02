#include "so_long.h"

void	map_free(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
}

void	error_free(char *msg, char *s1, char *s2, int err)
{
	free(s1);
	if (s2)
		free(s2);	
	error_handler(msg, err);
}

void	error_handler(char *msg, int err)
{
	perror(msg);
	exit(err);
}