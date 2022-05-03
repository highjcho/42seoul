/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:10:47 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 10:10:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	while (++i < g->hei - 1) // 조건에 이상없는 지 확인 필요
	{
		if (g->map[i][0] != '1' || g->map[i][g->wid - 1] != '1')
			map_error(g, "Error\nso_long: The map must be closed by walls");
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
				map_error(g, "Error\nso_long: The map contains invalid characters");
		}
	}
}

void	check_map(t_game *g)
{
	check_outside(g);
	check_inside(g);
	if (g->p.p != 1 || !g->item || !g->exit)
		map_error(g, "Error\nso_long: Invalid number of components in map");
}
