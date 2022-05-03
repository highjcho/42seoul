/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:28:08 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 09:30:13 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	win_game(t_game *g)
{
	map_free(g);
	mlx_destroy_image(g->m, g->i.p);
	mlx_destroy_image(g->m, g->i.w);
	mlx_destroy_image(g->m, g->i.r);
	mlx_destroy_image(g->m, g->i.i);
	mlx_destroy_image(g->m, g->i.e);
	mlx_destroy_window(g->m, g->w);
	printf("so_long: Escape uccess! You're total move count: %d", g->p.move);
	exit(EXIT_SUCCESS);
}

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

