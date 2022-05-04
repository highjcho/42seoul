/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:27:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 09:27:43 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_game *g, int wid, char *s1, char *s2)
{
	if (g->wid != wid)
	{
		free(s1);
		free(s2);
		map_error(g, "Error\nso_long: The map must be rectangular");
	}
}

static void	check_outside(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->wid)
	{
		if (g->map[0][i] != '1' || g->map[g->hei - 1][i] != '1')
			map_error(g, "Error\nso_long: The map must be closed by walls");
	}
	i = 0;
	while (++i < g->hei - 1)
	{
		if (g->map[i][0] != '1' || g->map[i][g->wid - 1] != '1')
			map_error(g, "Error\nso_lon: The map must be closed by walls");
	}
}

static void	check_inside(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (++i < g->hei)
	{
		j = 0;
		while (++j < g->wid)
		{
			if (g->map[i][j] == 'P')
			{
				g->p.p++;
				g->p.x = j;
				g->p.y = i;
			}
			else if (g->map[i][j] == 'C')
				g->item++;
			else if (g->map[i][j] == 'E')
				g->exit++;
			else if (g->map[i][j] != '1' && g->map[i][j] != '0')
				map_error(g, "Error\nThe map contains invalid characters");
		}
	}
}

void	check_map(t_game *g)
{
	check_outside(g);
	check_inside(g);
	if (g->p.p != 1 || !g->item || !g->exit)
		map_error(g, "Error\nInvalid number of components on the map");
}