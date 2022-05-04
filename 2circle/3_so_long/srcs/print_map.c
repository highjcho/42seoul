/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:29:24 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 09:29:35 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_new_p(t_game *g, int flag, int new_r)
{
	if (flag == 1)
		mlx_put_image_to_window(g->m, g->w, g->i.r, g->p.x * 64, g->p.y * 64);
	else if (flag == 2)
		mlx_put_image_to_window(g->m, g->w, g->i.r, g->p.x * 64, new_r * 64);
	else if (flag == 3)
		mlx_put_image_to_window(g->m, g->w, g->i.r, new_r * 64, g->p.y * 64);
	else
		mlx_put_image_to_window(g->m, g->w, g->i.p, g->p.x * 64, g->p.y * 64);
}

static void	set_image(t_game *g)
{
	int	w;
	int	h;

	g->i.p = mlx_xpm_file_to_image(g->m, "./imgs/player.xpm", &w, &h);
	g->i.w = mlx_xpm_file_to_image(g->m, "./imgs/wall.xpm", &w, &h);
	g->i.r = mlx_xpm_file_to_image(g->m, "./imgs/road.xpm", &w, &h);
	g->i.i = mlx_xpm_file_to_image(g->m, "./imgs/item.xpm", &w, &h);
	g->i.c = mlx_xpm_file_to_image(g->m, "./imgs/close.xpm", &w, &h);
	g->i.e = mlx_xpm_file_to_image(g->m, "./imgs/exit.xpm", &w, &h);
	if (!g->i.p || !g->i.w || !g->i.r || !g->i.i || !g->i.c || !g->i.e)
	{
		destroy_all(g);
		error_handler("so_long: set image fail", errno);
	}
}

void	print_map(t_game *g)
{
	int		i;
	int		j;

	set_image(g);
	i = -1;
	while (++i < g->hei)
	{
		j = -1;
		while (++j < g->wid)
		{
			mlx_put_image_to_window(g->m, g->w, g->i.r, j * 64, i * 64);
			if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->m, g->w, g->i.p, j * 64, i * 64);
			else if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->m, g->w, g->i.c, j * 64, i * 64);
			else if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->m, g->w, g->i.i, j * 64, i * 64);
			else if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->m, g->w, g->i.w, j * 64, i * 64);
		}
	}
}