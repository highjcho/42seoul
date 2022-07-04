/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:57:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/04 19:09:19 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	do_philo(t_info *info, t_philo *philo)
{
	while (info->play)
	{
		take_fork(info, philo);
		do_sleep(info, philo);
		do_think(info, philo);
	}
}

static void	one_philo(t_info *info)
{
	t_philo	*philo;

	philo = &(info->philos[0]);
	pthread_mutex_lock(&info->forks[philo->first]);
	print_philo(info, philo, get_cur_time() - info->start, 0);
	pthread_mutex_unlock(&info->forks[philo->first]);
}

void	*start_philo(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	info = (t_info *)arg;
	philo = &info->philos[info->id];
	pthread_mutex_lock(&info->done);
	pthread_mutex_unlock(&info->done);
	philo->starve = info->start + info->t_die;
	if (info->count == 1)
		one_philo(info);
	else if (philo->id % 2 == 0)
		do_philo(info, philo);
	else
	{
		usleep(5);
		do_philo(info, philo);
	}
	return (NULL);
}
