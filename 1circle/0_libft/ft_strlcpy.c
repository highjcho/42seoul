/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:53:30 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/06 14:04:26 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const	char	*src, size_t	dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize != 0)
	{
		while (dstsize-- > 1 && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (src_len);
}
