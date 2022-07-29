/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:01:40 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/13 17:33:23 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

char	*quote_trim(char *str, int pos1, int pos2)
{
	char	*ret;
	int		i;
	int		index;

	i = -1;
	index = 0;
	ret = malloc(ft_strlen(str) - 1);
	if (!str)
		return (NULL);
	while (str[++i])
	{
		if (i != pos1 && i != pos2)
		{
			ret[index] = str[i];
			index++;
		}
	}
	ret[index] = 0;
	return (ret);
}

char	*double_quote_trim(char *str, int *pos1, int pos2)
{
	int	i;
	int	tmp;

	str = quote_trim(str, *pos1, pos2);
	tmp = ft_strlen(str);
	i = *pos1 - 1;
	while (str[++i] && i < pos2 - 2)
	{
		if (str[i] == '$')
		{
			str = substitution(str, &i, pos2 - 2, i - 1);
			pos2 -= tmp - ft_strlen(str);
		}
	}
	*pos1 = i - 1;
	return (str);
}
