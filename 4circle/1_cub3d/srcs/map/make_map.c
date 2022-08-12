/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:46 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/09 23:56:28 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	set_player_pos(t_info *info, int i, int j)
{
	info->player->pos.x = j + 0.5;
	info->player->pos.y = i + 0.5;
}

static void	fill_map(t_info *info, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (line)
	{
		info->map->map[i] = ft_calloc(info->map->width, sizeof(char));
		if (!info->map->map[i])
			exit_error("Failed to allocate memory");
		j = 0;
		while (line[j] && line[j] != '\n')
		{
			info->map->map[i][j] = line[j];
			if (line[j] == info->map->start_dir)
				set_player_pos(info, i, j);
			j++;
		}
		while (j < info->map->width - 1)
			info->map->map[i][j++] = ' ';
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	make_map(t_info *info, char *file)
{
	t_map	*map;
	int		fd;
	int		count;
	char	*line;

	map = info->map;
	map->height = map->end - map->start + 1;
	map->map = ft_calloc((map->height + 1), sizeof(char *));
	if (!map->map)
		exit_error("Failed to allocate memory");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open file");
	count = 0;
	line = get_next_line(fd);
	while (line && ++count <= map->start - 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	fill_map(info, line, fd);
	close(fd);
	check_wall(info);
}
