/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:27 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/09 23:30:34 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_valid_word(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_strchr(" 01NSWE", line[i]))
	{
		if (ft_strchr("NSWE", line[i]))
		{
			if (map->player > 0)
				exit_error("Too many players");
			map->player = 1;
			map->start_dir = line[i];
		}
		i++;
	}
	if (line[i] && line[i] != '\n')
		exit_error("Invalid character");
	if (i > map->width)
		map->width = i;
	if (map->start == 0)
		map->start = map->end;
}

void	check_wall(t_info *info)
{
	char	**map;
	int		i;
	int		j;

	map = info->map->map;
	i = -1;
	while (++i < info->map->height)
	{
		j = -1;
		while (++j < info->map->width)
		{
			if (map[i][j] == '0' || map[i][j] == info->map->start_dir)
			{
				if (i == 0 || i == info->map->height - 1 \
					|| j == 0 || j == info->map->width - 1)
					exit_error("Not surrounded by wall");
				else if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || \
					map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					exit_error("Not surrounded by wall");
			}
		}
	}
}
