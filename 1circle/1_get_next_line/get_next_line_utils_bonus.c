/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:55:29 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/20 15:55:33 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t	count, size_t	size)
{
	char	*result;

	result = (char *)malloc(count * size);
	if (!result)
		return (0);
	ft_bzero(result, (count * size));
	return (result);
}

void	ft_bzero(void	*s, size_t len)
{
	unsigned char	 *ptr;

	ptr = (unsigned char *)s;
	while (len-- > 0)
		*ptr++ = 0;
}

void	ft_memmove(void	*dst, void	*src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (len-- > 0)
		*pdst++ = *psrc++;
}

size_t	ft_len(char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}
