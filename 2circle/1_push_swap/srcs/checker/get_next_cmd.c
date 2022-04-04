/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:51:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 13:51:29 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strchr(char *s)
{
	if (!s)
		return (0);
	while (*s && *s != '\n')
		s++;
	if (*s == '\n')
		return (0);
	return (1);
}

static char	*ft_calloc(int count)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * count);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < count)
		s[i] = 0;
	return (s);
}

static void	ft_memmove(char *s, int len)
{
	int	i;
	int	j;

	i = -1;
	j = len;
	while (++i < BUFFER - len)
		s[i] = s[j++];
	while (i < BUFFER)
		s[i++] = 0;
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_ret;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_ret = ft_calloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_ret)
	{
		free(s1);
		return (NULL);
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

char	*get_next_cmd(int *flag)
{
	static char	buf[BUFFER + 1];
	char		*cmd;

	cmd = ft_calloc(1);
	if (!cmd)
		*flag = -1;
	while (ft_strchr(cmd))
	{
		if (!buf[0])
		{
			*flag = read(0, buf, BUFFER);
			if (!(*flag) && cmd[0])
				return (cmd);
			else if (*flag < 0 || (!(*flag) && !cmd[0]))
			{
				free(cmd);
				return (NULL);
			}
		}
		cmd = ft_strjoin(cmd, buf);
		if (!cmd)
			*flag = -1;
	}
	return (cmd);
}
