/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:34:35 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/21 15:32:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	int			read_result;

	result = (char *)ft_calloc(1, sizeof(char));
	if (!result)
		return (0);
	while (!ft_strchr(result))
	{
		if (buf[0] == 0)
		{
			read_result = read(fd, buf, BUFFER_SIZE);
			if (!read_result && result[0] != 0)
				return (result);
			else if ((read_result < 0) || (!read_result && result[0] == 0))
			{
				free(result);
				return (0);
			}
		}
		result = make_line(buf, result);
	}
	return (result);
}

char	*make_line(char *buf, char *result)
{
	size_t	len;
	char	*tmp;
	char	*new_result;

	len = ft_len(buf);
	tmp = (char *)ft_calloc((len + 1), sizeof(char));
	if (!tmp)
		return (0);
	ft_strncpy(tmp, buf, len);
	ft_memmove(buf, buf + len, BUFFER_SIZE - len);
	ft_bzero(buf + BUFFER_SIZE - len, len);
	new_result = ft_strjoin(result, tmp);
	return (new_result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_result;
	size_t	i;
	size_t	j;

	new_result = (char *)ft_calloc((ft_len(s1) + ft_len(s2) + 1), sizeof(char));
	if (!new_result)
		return (0);
	i = -1;
	while (s1[++i])
		new_result[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_result[i + j] = s2[j];
	free(s1);
	free(s2);
	return (new_result);
}

void	ft_strncpy(char *dst, char *src, size_t dstsize)
{
	while (dstsize-- > 0)
		*dst++ = *src++;
}

char	*ft_strchr(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (0);
}
