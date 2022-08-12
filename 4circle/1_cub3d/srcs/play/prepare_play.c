/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:51 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/05 17:55:52 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static t_vector	set_dir(t_player *player, int key)
{
	t_vector	dir;

	dir.x = player->dir.x;
	dir.y = player->dir.y;
	if (key == KEY_S)
	{
		dir.x *= -1;
		dir.y *= -1;
	}
	else if (key == KEY_A)
	{
		dir.x = player->dir.y;
		dir.y = player->dir.x * -1;
	}
	else if (key == KEY_D)
	{
		dir.x = player->dir.y * -1;
		dir.y = player->dir.x;
	}
	return (dir);
}

int	check_edge(char **map, t_player *player, t_vector *next_pos, int key)
{
	t_vector	dir;
	int			next_x;
	int			next_y;

	dir = set_dir(player, key);
	next_x = (int)next_pos->x;
	next_y = (int)next_pos->y;
	if (dir.x < 0 && dir.y < 0)
		return (map[next_y + 1][next_x] == '1' && \
			map[next_y][next_x + 1] == '1');
	if (dir.x > 0 && dir.y < 0)
		return (map[next_y + 1][next_x] == '1' && \
			map[next_y][next_x - 1] == '1');
	if (dir.x < 0 && dir.y > 0)
		return (map[next_y - 1][next_x] == '1' && \
			map[next_y][next_x + 1] == '1');
	if (dir.x > 0 && dir.y > 0)
		return (map[next_y - 1][next_x] == '1' && \
			map[next_y][next_x - 1] == '1');
	return (0);
}

t_vector	set_offset(t_player *player, int key)
{
	t_vector	offset;

	offset.x = player->dir.x * MOVE_SPEED;
	offset.y = player->dir.y * MOVE_SPEED;
	if (key == KEY_S)
	{
		offset.x = player->dir.x * MOVE_SPEED * -1;
		offset.y = player->dir.y * MOVE_SPEED * -1;
	}
	else if (key == KEY_A)
	{
		offset.x = player->plane.x * MOVE_SPEED * -1;
		offset.y = player->plane.y * MOVE_SPEED * -1;
	}
	else if (key == KEY_D)
	{
		offset.x = player->plane.x * MOVE_SPEED;
		offset.y = player->plane.y * MOVE_SPEED;
	}
	return (offset);
}
