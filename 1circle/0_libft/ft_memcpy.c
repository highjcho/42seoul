/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:17:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/11/17 17:04:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = dst;
	psrc = src;
	if (!dst && !src)
		return (0);
	while (n-- > 0)
		*pdst++ = *psrc++;
	return (dst);
}
