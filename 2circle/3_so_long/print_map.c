#include "so_long.h"

static void	set_image(t_game *g, t_img *img) // 오류 반환값 확인
{
	int	width;
	int	height;

	img->p = mlx_xpm_file_to_image(g->mlx, "./imgs/player.xpm", &width, &height); // 할당 해제 해줘야 하나?
	img->wall = mlx_xpm_file_to_image(g->mlx, "./imgs/wall.xpm", &width, &height);
	img->path = mlx_xpm_file_to_image(g->mlx, "./imgs/path.xpm", &width, &height);
	img->item = mlx_xpm_file_to_image(g->mlx, "./imgs/item.xpm", &width, &height);
	img->exit = mlx_xpm_file_to_image(g->mlx, "./imgs/exit.xpm", &width, &height);
}

void	print_new_p(t_game *game, t_img *img, int flag, int new_r)
{
	if (flag == 1)
		mlx_put_image_to_window(game->mlx, game->win, img->path, game->p.x * 64, game->p.y * 64);
	else if (flag == 2)
		mlx_put_image_to_window(game->mlx, game->win, img->path, game->p.x * 64, new_r * 64);
	else if (flag == 3)
		mlx_put_image_to_window(game->mlx, game->win, img->path, new_r * 64, game->p.y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, img->p, game->p.x * 64, game->p.y * 64);
}

void	print_map(t_game *game) // 줄길면 mlx, win 포인터 변수 만들어서 거기다 대입해서 하자
{
	t_img	img;
	int		i;
	int		j;

	set_image(game, &img);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, img.path, j * 64, i * 64);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, img.p, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, img.exit, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, img.item, j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, img.wall, j * 64, i * 64);
			else
		}
	}
}