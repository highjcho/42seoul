/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:12:30 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/03 19:06:52 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*s, int	c, size_t	n)
{
	unsigned const char	*ptr;

	ptr = (unsigned const char *)s;
	while (n > 0)
	{
		if (*ptr == (unsigned const char)c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (0);
}
