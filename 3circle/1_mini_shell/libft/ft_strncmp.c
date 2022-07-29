/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:14:09 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/06 18:55:49 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (str1[i] && str2[i] && str1[i] == str2[i] && i + 1 < n)
		i++;
	return (str1[i] - str2[i]);
}
