/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:15:25 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/06 11:53:40 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const	char	*find_s, size_t	len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find_s[i] == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == find_s[j] && i + j < len)
		{
			j++;
			if (find_s[j] == 0)
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
