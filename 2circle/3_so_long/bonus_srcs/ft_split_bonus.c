/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:11:09 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 10:11:17 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	find_c(char const s, char c)
{
	if (s == c)
		return (0);
	if (s == 0)
		return (0);
	return (1);
}

static void	make_str(char *new_strs, char const *s, char c)
{
	int	i;

	i = 0;
	while (find_c(s[i], c) == 1)
	{
		new_strs[i] = s[i];
		i++;
	}
}

static int	ft_free(char **new_strs, int j)
{
	int	i;

	i = 0;
	while (new_strs[i])
	{
		ft_bzero(new_strs[i], j);
		free(new_strs[i]);
		i++;
	}
	free(new_strs);
	return (0);
}

static int	split_str(char **new_strs, char const *s, char c)
{
	int	str;
	int	i;
	int	j;

	str = 0;
	i = 0;
	while (s[i])
	{
		if (find_c(s[i], c) == 0)
			i++;
		else
		{
			j = 0;
			while (find_c(s[i + j], c) == 1)
				j++;
			new_strs[str] = (char *)ft_calloc((j + 1), sizeof(char));
			if (new_strs[str] == 0)
				return (ft_free(new_strs, j));
			make_str(new_strs[str], s + i, c);
			str++;
			i += j;
		}
	}
	return (1);
}

char	**ft_split(t_game *game, char const *s, char c)
{
	char	**new_strs;
	int		strs;
	int		i;

	strs = 0;
	i = 0;
	while (s[i])
	{
		if (find_c(s[i], c) == 1 && find_c(s[i + 1], c) == 0)
			strs++;
		i++;
	}
	game->hei = strs;
	new_strs = (char **)ft_calloc((strs + 1), sizeof(char *));
	if (!new_strs)
		return (NULL);
	if (split_str(new_strs, s, c) == 0)
		return (NULL);
	return (new_strs);
}
