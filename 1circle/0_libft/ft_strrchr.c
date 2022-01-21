/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:14:27 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/01 18:06:43 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int	c)
{
	int	last_i;

	last_i = ft_strlen(s);
	while (last_i >= 0)
	{
		if (s[last_i] == (char)c)
			return ((char *)s + last_i);
		last_i--;
	}
	return (0);
}
