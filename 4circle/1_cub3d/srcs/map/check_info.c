/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:29 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/10 15:20:07 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	set_tex_file(t_map *map, int dir, char *path)
{
	if (map->tex_files[dir])
		exit_error("Only one texture is valid");
	map->tex_files[dir] = path;
}

void	check_texture(t_map *map, char *line, char c)
{
	int		i;
	char	*tmp;
	int		dir;

	i = 3;
	while (ft_isspace(line[i]))
		i++;
	tmp = ft_strdup(line + i, ft_strlen(line + i) - 1);
	if (!tmp)
		exit_error("Failed to allocate memory");
	if (c == 'N')
		dir = NORTH;
	else if (c == 'S')
		dir = SOUTH;
	else if (c == 'E')
		dir = EAST;
	else
		dir = WEST;
	set_tex_file(map, dir, tmp);
}

static void	to_rgb(t_map *map, int *color, char c)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			exit_error("Invalid RGB color");
	}
	if (c == 'F')
		map->floor = color[0] << 16 | color[1] << 8 | color[2];
	else
		map->ceil = color[0] << 16 | color[1] << 8 | color[2];
}

void	check_color(t_map *map, char *line)
{
	int	i;
	int	cnt;
	int	color[3];

	i = 2;
	cnt = 0;
	while (line[i] && cnt <= 2)
	{
		color[cnt] = -1;
		while (ft_isspace(line[i]))
			i++;
		if (ft_isdigit(line[i]))
			color[cnt] = ft_atoi(line + i);
		while (line[i] && (ft_isdigit(line[i]) || line[i] == '\n'))
			i++;
		if (line[i] && line[i] != ',')
			exit_error("Invalid RGB color");
		if (line[i] && line[i++] == ',')
			cnt++;
	}
	if (cnt != 2)
		exit_error("Invalid RGB color");
	to_rgb(map, color, line[0]);
}

void	check_info(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!map->tex_files[i])
			exit_error("No texture file");
		i++;
	}
	if (map->floor < 0 || map->ceil < 0)
		exit_error("No floor or ceiling color");
}
