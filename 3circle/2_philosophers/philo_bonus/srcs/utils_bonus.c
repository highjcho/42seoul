/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:06:02 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/11 19:08:09 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	print_philo(t_info *info, t_philo *philo, long time, int flag)
{
	pthread_mutex_lock(&info->print);
	if (!info->play)
	{
		pthread_mutex_unlock(&info->print);
		return ;
	}
	if (flag == 0)
		printf("%s%ld %d has taken fork\n", FORK, time, philo->id);
	else if (flag == 1)
		printf("%s%ld %d is eating\n", EAT, time, philo->id);
	else if (flag == 2)
		printf("%s%ld %d is sleeping\n", SLEEP, time, philo->id);
	else if (flag == 3)
		printf("%s%ld %d is thinking\n", THINK, time, philo->id);
	pthread_mutex_unlock(&info->print);
}

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (FALSE);
}

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
