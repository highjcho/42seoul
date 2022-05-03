/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:12:34 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 10:12:41 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	map_error(t_game *g, char *msg)
{
	free(g->map);
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	map_free(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
}

void	destroy_all(t_game *g)
{
	map_free(g);
	if (g->i.p)
		mlx_destroy_image(g->m, g->i.p);
	if (g->i.w)
		mlx_destroy_image(g->m, g->i.w);
	if (g->i.r)
		mlx_destroy_image(g->m, g->i.r);
	if (g->i.i)
		mlx_destroy_image(g->m, g->i.i);
	if (g->i.c)
		mlx_destroy_image(g->m, g->i.c);
	if (g->i.e)
		mlx_destroy_image(g->m, g->i.e);
	mlx_destroy_window(g->m, g->w);
}

void	error_free(char *msg, char *s1, char *s2, int err)
{
	free(s1);
	if (s2)
		free(s2);
	error_handler(msg, err);
}

void	error_handler(char *msg, int err)
{
	perror(msg);
	exit(err);
}
