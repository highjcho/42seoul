/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:13:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/17 15:33:48 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1 || !s2)
		return (0);
	new = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new)
		return (0);
	i = -1;
	while (++i < ft_strlen(s1))
		new[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		new[i + j] = s2[j];
	return (new);
}
