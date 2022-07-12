/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:06:02 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/12 18:06:20 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_cur_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(char *s)
{
	long	result;
	long	tmp;

	result = 0;
	if (!s)
		return (-1);
	if (*s == '-')
		return (-1);
	if (*s == '+')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);
		tmp = result;
		result = (result * 10) + (*s - '0');
		if (result / 10 != tmp)
			return (-1);
		s++;
	}
	return (result);
}
