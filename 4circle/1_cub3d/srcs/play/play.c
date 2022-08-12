/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:56 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/08 17:56:38 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static void	move(char **map, t_player *player, int key)
{
	t_vector	pos;
	t_vector	next_pos;
	t_vector	offset;

	pos.x = player->pos.x;
	pos.y = player->pos.y;
	offset = set_offset(player, key);
	next_pos.x = pos.x + offset.x;
	next_pos.y = pos.y + offset.y;
	if (map[(int)next_pos.y][(int)next_pos.x] != '1')
	{
		if (((int)pos.y != (int)next_pos.y || (int)pos.x != (int)next_pos.x) \
			&& check_edge(map, player, &next_pos, key))
			return ;
		player->pos.x = next_pos.x;
		player->pos.y = next_pos.y;
	}
}

static void	rotate(t_player *player, double sin_val, double cos_val)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos_val - player->dir.y * sin_val;
	player->dir.y = old_dir_x * sin_val + player->dir.y * cos_val;
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos_val - player->plane.y * sin_val;
	player->plane.y = old_plane_x * sin_val + player->plane.y * cos_val;
}

int	play(int key, t_info *info)
{
	char		**map;
	t_player	*player;

	map = info->map->map;
	player = info->player;
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		move(map, player, key);
	else if (key == KEY_LEFT)
		rotate(player, sin(-ROT_SPEED), cos(-ROT_SPEED));
	else if (key == KEY_RIGHT)
		rotate(player, sin(ROT_SPEED), cos(ROT_SPEED));
	else if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D \
		|| key == KEY_LEFT || key == KEY_RIGHT)
		draw_screen(info);
	return (0);
}
