/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:40:39 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/01 14:33:51 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char	(*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*new;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	new = (char *)ft_calloc((s_len + 1), sizeof(char));
	if (!new)
		return (0);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
