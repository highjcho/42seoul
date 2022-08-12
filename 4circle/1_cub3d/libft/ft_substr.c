/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:12:31 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 20:27:24 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	i;

	if (!s || len <= 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (start >= s_len)
	{
		len = 0;
		return (NULL);
	}
	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (s[start] && i < len)
		new[i++] = s[start++];
	return (new);
}
