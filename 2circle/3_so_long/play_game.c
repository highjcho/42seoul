#include "so_long.h"

static void	move_up_down(t_game *game, char map, int ny)
{
	if (map == '1' || (map == 'E' && game->item))
		return ;
	if (!game->item && map == 'E')
		exit_game(game);
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

static void	set_up_down(t_game *game, int direction)
{
	char	map;
	int		ny;

	if (direction == UP)
		ny = game->p.y - 1;
	else
		ny = game->p.y + 1;
	map = game->map[ny][game->p.x];
	move_up_down(game, map, ny);
}

static void	move_left_right(t_game *game, char map, int nx)
{
	if (map == '1' || (map == 'E' && game->item))
		return ;
	if (!game->item && map == 'E')
		exit_game(game);
	game->map[game->p.y][game->p.x] = '0';
	print_new_p(game, 1, 0);
	if (map == 'C')
	{
		game->item--;
		print_new_p(game, 3, nx);
	}
	game->map[game->p.y][nx] = 'P';
	game->p.x = nx;
	print_new_p(game, 4, 0);
}

static void	set_left_right(t_game *game, int direction)
{
	char	map;
	int		nx;

	if (direction == LEFT)
		nx = game->p.x - 1;
	else
		nx = game->p.x + 1;
	map = game->map[game->p.y][nx];
	move_left_right(game, map, nx);
}

int	play_game(int key_code, t_game *game) // 반환값? 마우스 처리는 어디서? exit_game을 따로 하든 아니면 play_game을 메인으로 빼기
{
	if (key_code == ESC)
		exit_game(game);
	else if (key_code == W)
		set_up_down(game, UP);
	else if (key_code == A)
		set_left_right(game, LEFT);
	else if (key_code == S)
		set_up_down(game, DOWN);
	else if (key_code == D)
		set_left_right(game, RIGHT);
	game->p.move++;
	printf("moves: %d\n", game->p.move);
	return (0); // 다른 키가 들어오면 걍 아무 동작도 안하면 되는건가? 함수 보이드? 인트?
}