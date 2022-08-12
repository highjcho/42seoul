/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:31:05 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/06 22:32:43 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

# include "cub3d.h"

// prepare_draw.c
void		set_args(t_info *info, t_args *args, int x);
void		find_wall_hit(t_info *info, t_args *args);
int			find_tex_num(t_args *args);
void		set_args_line(t_info *info, t_args *args, \
				int *draw_start, int *draw_end);

// draw.c
int			draw_screen(t_info *info);

// prepare_play.c
int			check_edge(char **map, t_player *player, \
				t_vector *next_pos, int key);
t_vector	set_offset(t_player *player, int key);

// play.c
int			play(int key, t_info *info);

#endif
