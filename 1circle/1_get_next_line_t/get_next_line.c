/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:34:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/14 18:17:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_calloc(int len, int size) 
{
	char *new;
	int	i;

	i = 0;
	new = (char *)malloc(len * size);
	if (!new)
		return (0);
	while (new[i])
	{
		new[i] = 0;
		i++;
	}
	return (new);
}

static int ft_len(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char *ft_strjoin(char *saved, char *buff, int s_len, int b_len)
{
	char *tmp;
	int i;
	int j;

	tmp = (char *)ft_calloc((s_len + b_len + 1), sizeof(char));
	if (!tmp)
		return (0);
	i = 0;
	while (i < s_len)
	{
		tmp[i] = *saved[i];
		i++;
	}
	j = 0;
	while (j < b_len)
	{
		tmp[i + j] = buff[j];
		j++;
	}
	return (tmp);
}

static char *return_line(char *buff, char *saved, int fd, int BUFFER_SIZE)
{ // b_len < buffer_size 하고, b_len == buffer_size하고 함수 분리 필요
	char *tmp;
	int s_len;
	int b_len;
	int t_len;
	int i;

	s_len = ft_len(saved);
	while ((read(fd, buff, BUFFER_SIZE) > 0))
	{
		b_len = ft_len(buff);
		if (b_len < BUFFER_SIZE)
		{
			tmp = ft_strjoin(saved, buff, s_len, b_len);
			if (s_len > 0)
				free(saved);
			saved = (char *)malloc((ft_len(buff + b_len) + 1) * sizeof(char));
			if (!saved)
				return (0);
			i = 0;
			while (buff[b_len])
			{
				saved[i] = buff[b_len];
				i++;
				b_len++;
			}
			saved[i] = 0;
			printf("saved : %s\n\n", *saved);
			printf("saved p: %p\n", *saved);
			return (tmp);
		}
		else if (b_len == BUFFER_SIZE)
		{
			t_len = ft_len(tmp);
			if (t_len > 0)
				free(tmp);
			tmp = ft_strjoin(saved, buff, s_len, b_len);
			free(saved);
			saved = (char *)malloc((ft_len(tmp) + 1) * sizeof(char));
			if (!saved)
				return (0);
			i = 0;
			while (i < t_len)
			{
				saved[i] = tmp[i];
				i++;
			}
		}
	}
	return (tmp);
}

char	*new_line(char	*saved)
{
	char	*tmp;

	tmp = ft_strjoin(saved, buff, s_len, b_len);
	if (s_len > 0)
		free(saved);
	saved = (char *)malloc((ft_len(buff + b_len) + 1) * sizeof(char));
	if (!saved)
		return (0);
	i = 0;
	while (buff[b_len])
	{
		saved[i] = buff[b_len];
		i++;
		b_len++;
	}
	saved[i] = 0;
	printf("saved : %s\n\n", *saved);
	printf("saved p: %p\n", *saved);
	return (tmp);
}

char	*get_next_line(int fd, int BUFFER_SIZE)
{
	static char *saved;
	char *buff;
	char *result;
	//int			flag;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (0);
	while ((read(fd, buff, BUFFER_SIZE) > 0))
	{
		if (ft_len(buff) != BUFFER_SIZE)
		{
			if (ft_len(saved) = 0)
			{
				saved = buff;
				make_line()
			}
			else
				ft_strjoin(saved, buff, ft_len(saved), ft_len(buff));
		}
	}
	result = 0;
	//flag = 0;
	if ((result = return_line(buff, saved, fd, BUFFER_SIZE)) == 0)
		return (0); //if가 필요한지? saved 할당 실패경우에 해줘야 겠다
	printf("saved main: %s\n", *saved);
	free(saved);
	free(buff);
	return (result);
}
