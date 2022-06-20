/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:55:50 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/05 14:55:51 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	redraw_img(t_game *g)
{
	if (g->p.moves > 1)
	{
		if (g->map[1][1] == '1')
			mlx_put_image_to_window(g->m, g->w, g->i.w, 64, 64);
		else if (g->map[1][1] == '0')
			mlx_put_image_to_window(g->m, g->w, g->i.r, 64, 64);
		else if (g->map[1][1] == 'P')
		{
			mlx_put_image_to_window(g->m, g->w, g->i.r, 64, 64);
			mlx_put_image_to_window(g->m, g->w, g->i.p, 64, 64);
		}
		else if (g->map[1][1] == 'C')
		{
			mlx_put_image_to_window(g->m, g->w, g->i.r, 64, 64);
			mlx_put_image_to_window(g->m, g->w, g->i.i, 64, 64);
		}
		else if (g->map[1][1] == 'E' && g->item)
			mlx_put_image_to_window(g->m, g->w, g->i.c, 64, 64);
		else if (g->map[1][1] == 'E' && !g->item)
			mlx_put_image_to_window(g->m, g->w, g->i.e, 64, 64);
	}
}

void	print_moves(t_game *g)
{
	g->text = ft_itoa(g->p.moves);
	if (!g->text)
	{
		destroy_all(g);
		error_handler("so_long: allocate failed", errno);
	}
	redraw_img(g);
	mlx_string_put(g->m, g->w, 64, 64, YELLOW, g->text);
	free(g->text);
}
