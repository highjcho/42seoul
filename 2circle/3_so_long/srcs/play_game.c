/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:28:00 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 09:28:29 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up_down(t_game *g, char map, int ny)
{
	g->map[g->p.y][g->p.x] = '0';
	print_new_p(g, 1, 0);
	if (map == 'C')
	{
		g->item--;
		if (!g->item)
			change_exit(g);
		print_new_p(g, 2, ny);
	}
	g->map[ny][g->p.x] = 'P';
	g->p.y = ny;
	print_new_p(g, 4, 0);
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
	g->p.moves++;
	if (map == 'E' && !g->item)
	{
		destroy_all(g);
		printf("moves: %d\n", g->p.moves);
		printf("so_long: Escape success! (total moves: %d)", g->p.moves);
		exit(EXIT_SUCCESS);
	}
	move_up_down(g, map, ny);
	printf("moves: %d\n", g->p.moves);
}

static void	move_left_right(t_game *g, char map, int nx)
{
	g->map[g->p.y][g->p.x] = '0';
	print_new_p(g, 1, 0);
	if (map == 'C')
	{
		g->item--;
		if (!g->item)
			change_exit(g);
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
	g->p.moves++;
	if (map == 'E' && !g->item)
	{
		destroy_all(g);
		printf("moves: %d\n", g->p.moves);
		printf("so_long: Escape success! (total moves: %d)", g->p.moves);
		exit(EXIT_SUCCESS);
	}
	move_left_right(g, map, nx);
	printf("moves: %d\n", g->p.moves);
}

int	play_game(int key_code, t_game *g)
{
	if (key_code == ESC)
		force_quit(g);
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
