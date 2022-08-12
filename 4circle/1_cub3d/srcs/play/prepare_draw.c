/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:49 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/08 16:25:12 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	set_args(t_info *info, t_args *args, int x)
{
	args->cam_x = 2 * x / (double)SCREEN_X - 1;
	args->ray_x = info->player->dir.x + info->player->plane.x * args->cam_x;
	args->ray_y = info->player->dir.y + info->player->plane.y * args->cam_x;
	args->map_x = (int)info->player->pos.x;
	args->map_y = (int)info->player->pos.y;
	args->delta_x = fabs(1 / args->ray_x);
	args->delta_y = fabs(1 / args->ray_y);
	args->step_x = -1;
	args->step_y = -1;
	if (args->ray_x < 0)
		args->side_x = (info->player->pos.x - args->map_x) * args->delta_x;
	else
	{
		args->step_x = 1;
		args->side_x = \
			(args->map_x + 1.0 - info->player->pos.x) * args->delta_x;
	}
	if (args->ray_y < 0)
		args->side_y = (info->player->pos.y - args->map_y) * args->delta_y;
	else
	{
		args->step_y = 1;
		args->side_y = \
			(args->map_y + 1.0 - info->player->pos.y) * args->delta_y;
	}
}

void	find_wall_hit(t_info *info, t_args *args)
{
	args->hit = 0;
	while (args->hit == 0)
	{
		if (args->side_x < args->side_y)
		{
			args->side_x += args->delta_x;
			args->map_x += args->step_x;
			args->side = HIT_X;
		}
		else
		{
			args->side_y += args->delta_y;
			args->map_y += args->step_y;
			args->side = HIT_Y;
		}
		if (info->map->map[args->map_y][args->map_x] == '1')
			args->hit = 1;
	}
}

int	find_tex_num(t_args *args)
{
	if (args->side == HIT_X)
	{
		if (args->ray_x < 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (args->ray_y < 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	set_args_line(t_info *info, t_args *args, \
			int *draw_start, int *draw_end)
{
	int	line_height;

	line_height = (int)(SCREEN_Y / args->perp_wall);
	*draw_start = -line_height / 2 + SCREEN_Y / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + SCREEN_Y / 2;
	if (*draw_end >= SCREEN_Y)
		*draw_end = SCREEN_Y - 1;
	if (args->side == HIT_X)
		args->wall_x = info->player->pos.y + args->perp_wall * args->ray_y;
	else
		args->wall_x = info->player->pos.x + args->perp_wall * args->ray_x;
	args->wall_x -= floor(args->wall_x);
	args->tex_x = (int)(args->wall_x * (double)TEX_WIDTH);
	if (args->side == HIT_X && args->ray_x > 0)
		args->tex_x = TEX_WIDTH - args->tex_x - 1;
	if (args->side == HIT_Y && args->ray_y < 0)
		args->tex_x = TEX_WIDTH - args->tex_x - 1;
	args->step = 1.0 * TEX_HEIGHT / line_height;
	args->tex_pos = (*draw_start - SCREEN_Y / 2 + line_height / 2) * args->step;
}
