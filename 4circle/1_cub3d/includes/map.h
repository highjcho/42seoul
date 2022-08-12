/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:31:00 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/06 22:31:00 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

// check_file.c
void	check_texture(t_map *map, char *line, char c);
void	check_color(t_map *map, char *line);
void	check_info(t_map *map);

// check_map.c
void	check_valid_word(t_map *map, char *line);
void	check_wall(t_info *info);

// make_map.c
void	make_map(t_info *info, char *file);

#endif
