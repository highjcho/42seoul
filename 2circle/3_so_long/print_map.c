#include "so_long.h"

static void	set_image(t_game *game, void *mlx) // 오류 반환값 확인
{
	int	width;
	int	height;

	game->img.p = mlx_xpm_file_to_image(mlx, "./imgs/player.xpm", &width, &height);
	game->img.wall = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &width, &height);
	game->img.path = mlx_xpm_file_to_image(mlx, "./imgs/path.xpm", &width, &height);
	game->img.item = mlx_xpm_file_to_image(mlx, "./imgs/item.xpm", &width, &height);
	// game->img.exit = mlx_xpm_file_to_image(mlx, "./imgs/exit.xpm", &width, &height);
	printf("%p\n",game->img.p);
	printf("%p\n",game->img.wall);
}

void	print_map(t_game *game, void *mlx, void *win)
{
	int	i;
	int	j;

	set_image(game, mlx);
	i = 0;
	(void)win;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, game->img.p, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, game->img.item, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, game->img.item, j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, game->img.wall, j * 64, i * 64);
			else
				mlx_put_image_to_window(mlx, win, game->img.path, j * 64, i * 64);
			j++;
		}
		i++;
	}
}