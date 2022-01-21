/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:12:50 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/11/30 15:12:13 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;
	size_t				i;

	if (n == 0)
		return (0);
	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	i = 0;
	while (ps1[i] == ps2[i] && i + 1 < n)
		i++;
	return (ps1[i] - ps2[i]);
}