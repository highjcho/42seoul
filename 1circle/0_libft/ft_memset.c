/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:34:47 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/03 19:01:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*s, int	c, size_t	len)
{
	unsigned char	*ptr;

	ptr = s;
	while (len-- > 0)
		*ptr++ = (unsigned char)c;
	return (s);
}
