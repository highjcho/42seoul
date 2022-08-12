/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:09 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/09 23:32:24 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	init_map(t_map *map)
{
	map->floor = -1;
	map->ceil = -1;
	map->tex_files = (char **)ft_calloc(4, sizeof(char *));
	if (!map->tex_files)
		exit_error("Failed to allocate memory");
}

void	init_info(t_info *info)
{
	info->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!info->map)
		exit_error("Failed to allocate memory");
	init_map(info->map);
	info->player = (t_player *)malloc(sizeof(t_player));
	if (!info->player)
		exit_error("Failed to allocate memory");
	info->mlx = mlx_init();
	if (!info->mlx)
		exit_error("Failed to initiate mlx");
	info->window = mlx_new_window(info->mlx, SCREEN_X, SCREEN_Y, "cub3D");
	if (!info->window)
		exit_error("Failed to create mlx winow");
	info->img = (t_img *)malloc(sizeof(t_img));
	if (!info->img)
		exit_error("Failed to allocate memory");
	info->img->img = mlx_new_image(info->mlx, SCREEN_X, SCREEN_Y);
	if (!info->img->img)
		exit_error("Failed to create mlx image");
	info->img->data = (char *)mlx_get_data_addr(info->img->img, \
		&info->img->bpp, &info->img->size_l, &info->img->endian);
	if (!info->img->data)
		exit_error("Failed to create mlx image data");
}

void	init_player(t_player *player, char dir)
{
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	if (dir == 'S')
	{
		player->plane.x = -0.66;
		player->dir.y = 1;
	}
	else if (dir == 'W' || dir == 'E')
	{
		player->plane.x = 0;
		player->plane.y = -0.66;
		player->dir.x = -1;
		player->dir.y = 0;
		if (dir == 'E')
		{
			player->dir.x = 1;
			player->plane.y = 0.66;
		}
	}
}

static void	load_image(t_info *info, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(info->mlx, path, \
		&texture->img_width, &texture->img_height);
	if (!texture->img)
		exit_error("Failed to load image");
	texture->data = (char *)mlx_get_data_addr(texture->img, &texture->bpp, \
		&texture->size_l, &texture->endian);
	if (!texture->data)
		exit_error("Failed to create mlx image data");
}

void	init_texture(t_info *info)
{
	t_map	*map;
	int		i;

	map = info->map;
	i = 0;
	while (i < 4)
	{
		load_image(info, &(map->texture[i]), map->tex_files[i]);
		i++;
	}
}
