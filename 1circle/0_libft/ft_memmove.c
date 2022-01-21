/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:54:25 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/11/29 19:20:21 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t len)
{
	size_t				i;
	unsigned char		*pdst;
	const unsigned char	*psrc;

	i = -1;
	pdst = dst;
	psrc = src;
	if (!dst && !src)
		return (0);
	while (++i < len)
	{
		if (dst < src)
			*pdst++ = *psrc++;
		else
			*(pdst + len - 1 - i) = *(psrc + len - 1 - i);
	}
	return (dst);
}
