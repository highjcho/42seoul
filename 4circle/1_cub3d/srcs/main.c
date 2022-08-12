/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:54:55 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/08 17:56:14 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_filename(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strcmp(".cub", path + len - 4) == 0)
		return (TRUE);
	return (FALSE);
}

static void	check_mapfile(t_map *map, char *line)
{
	if (line[0] == '\n')
		return ;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) \
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		check_texture(map, line, line[0]);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		check_color(map, line);
	else if (ft_strchr(" 01NSWE", line[0]))
	{
		if (map->has_info == FALSE)
		{
			check_info(map);
			map->has_info = TRUE;
		}
		check_valid_word(map, line);
	}
}

static void	read_mapfile(t_map *map, char *path)
{
	int		fd;
	char	*line;

	if (check_filename(path) == FALSE)
		exit_error("Invalid map file");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open file");
	line = get_next_line(fd);
	while (line)
	{
		map->end += 1;
		check_mapfile(map, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!map->player)
		exit_error("No player");
	close(fd);
}

static int	force_quit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		exit_error("Usage: ./cub3D map.cub");
	init_info(&info);
	read_mapfile(info.map, av[1]);
	init_player(info.player, info.map->start_dir);
	make_map(&info, av[1]);
	init_texture(&info);
	draw_screen(&info);
	mlx_hook(info.window, PRESS_KEY, 0, play, &info);
	mlx_hook(info.window, MOUSE_EXIT, 0, force_quit, &info);
	mlx_loop(info.mlx);
	return (0);
}
