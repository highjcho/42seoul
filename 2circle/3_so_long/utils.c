#include "so_long.h"

void	double_free(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	error_handler(char *msg, int err)
{
	perror(msg);
	exit(err);
}