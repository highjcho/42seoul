/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:11:27 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 10:11:34 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (0);
	return (1);
}

static void	ft_memmove(char *s, int len)
{
	int	i;
	int	j;

	i = -1;
	j = len;
	while (++i < BUFFER_SIZE - len)
		s[i] = s[j++];
	while (i < BUFFER_SIZE)
		s[i++] = 0;
}

static char	*make_line(char *s1, char *s2, char *s)
{
	char	*new_ret;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_len(s1);
	s2_len = ft_len(s2);
	new_ret = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!new_ret)
	{
		free(s1);
		error_free("so_long: allocate failed", s, NULL, errno);
	}
	i = -1;
	while (++i < s1_len)
		new_ret[i] = s1[i];
	j = -1;
	while (++j < s2_len)
		new_ret[i + j] = s2[j];
	ft_memmove(s2, s2_len);
	free(s1);
	return (new_ret);
}

char	*get_next_line(int fd, char *s)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*ret;
	int			read_result;

	ret = ft_calloc(1, sizeof(char));
	if (!ret)
		error_free("so_long: allocate failed", s, NULL, errno);
	while (ft_strchr(ret))
	{
		if (!buf[0])
		{
			read_result = read(fd, buf, BUFFER_SIZE);
			if (!read_result && ret[0])
				return (ret);
			else if (!read_result && ret[0] == 0)
			{
				free(ret);
				return (NULL);
			}
			else if (read_result < 0)
				error_free("so_long: allocate failed", s, ret, errno);
		}
		ret = make_line(ret, buf, s);
	}
	return (ret);
}
