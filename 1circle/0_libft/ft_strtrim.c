/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:41:27 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/01 14:37:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	start;
	size_t	end;
	char	*new;
	size_t	i;	

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]) && end != 0)
		end--;
	if (start > end || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	new = (char *)ft_calloc((end - start + 2), sizeof(char));
	if (!new)
		return (0);
	i = -1;
	while (++i <= end - start)
		new[i] = s1[start + i];
	return (new);
}
