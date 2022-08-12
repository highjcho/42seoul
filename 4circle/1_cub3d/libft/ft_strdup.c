/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:50:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/08/04 17:45:31 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1, int count)
{
	char	*new;
	int		i;

	new = (char *)ft_calloc((count + 1), sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}
