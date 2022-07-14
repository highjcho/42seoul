/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:06:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/14 14:30:50 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_fork(t_info *info, t_philo *philo, long time)
{
	pthread_mutex_lock(&info->print);
	if (!info->play)
	{
		pthread_mutex_unlock(&info->print);
		return ;
	}
	printf("%s%ld %d has taken fork\n", FORK, time, philo->id);
	pthread_mutex_unlock(&info->print);
}

void	print_eat(t_info *info, t_philo *philo, long time)
{
	pthread_mutex_lock(&info->print);
	if (!info->play)
	{
		pthread_mutex_unlock(&info->print);
		return ;
	}
	printf("%s%ld %d is eating\n", EAT, time, philo->id);
	pthread_mutex_unlock(&info->print);
}

void	print_sleep(t_info *info, t_philo *philo, long time)
{
	pthread_mutex_lock(&info->print);
	if (!info->play)
	{
		pthread_mutex_unlock(&info->print);
		return ;
	}
	printf("%s%ld %d is sleeping\n", SLEEP, time, philo->id);
	pthread_mutex_unlock(&info->print);
}

void	print_think(t_info *info, t_philo *philo, long time)
{
	pthread_mutex_lock(&info->print);
	if (!info->play)
	{
		pthread_mutex_unlock(&info->print);
		return ;
	}
	printf("%s%ld %d is thinking\n", THINK, time, philo->id);
	pthread_mutex_unlock(&info->print);
}

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (FALSE);
}
