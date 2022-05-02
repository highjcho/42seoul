#include "so_long.h"

static void	move_up_down(t_game *game, char map, int ny)
{
	game->map[game->p.y][game->p.x] = '0';
	print_new_p(game, 1, 0);
	if (map == 'C')
	{
		game->item--;
		print_new_p(game, 2, ny);
	}
	game->map[ny][game->p.x] = 'P';
	game->p.y = ny;
	print_new_p(game, 4, 0);
}

static void	set_up_down(t_game *g, int direction)
{
	char	map;
	int		ny;

	if (direction == UP)
		ny = g->p.y - 1;
	else
		ny = g->p.y + 1;
	map = g->map[ny][g->p.x];
	if (map == '1' || (map == 'E' && g->item))
		return ;
	g->p.move++;
	printf("moves: %d\n", g->p.move);
	if (map == 'E' && !g->item)
		exit_game(g);
	move_up_down(g, map, ny);
}

static void	move_left_right(t_game *g, char map, int nx)
{
	g->map[g->p.y][g->p.x] = '0';
	print_new_p(g, 1, 0);
	if (map == 'C')
	{
		g->item--;
		print_new_p(g, 3, nx);
	}
	g->map[g->p.y][nx] = 'P';
	g->p.x = nx;
	print_new_p(g, 4, 0);
}

static void	set_left_right(t_game *g, int direction)
{
	char	map;
	int		nx;

	if (direction == LEFT)
		nx = g->p.x - 1;
	else
		nx = g->p.x + 1;
	map = g->map[g->p.y][nx];
	if (map == '1' || (map == 'E' && g->item))
		return ;
	g->p.move++;
	printf("moves: %d\n", g->p.move);
	if (map == 'E' && !g->item)
		exit_game(g);
	move_left_right(g, map, nx);
}

int	play_game(int key_code, t_game *g)
{
	if (key_code == ESC)
		exit_game(g);
	else if (key_code == W)
		set_up_down(g, UP);
	else if (key_code == A)
		set_left_right(g, LEFT);
	else if (key_code == S)
		set_up_down(g, DOWN);
	else if (key_code == D)
		set_left_right(g, RIGHT);
	return (0);
}