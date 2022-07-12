/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:25:43 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/12 18:52:04 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->forks[philo->first]);
	print_fork(info, philo, get_cur_time() - info->start);
	pthread_mutex_lock(&info->forks[philo->second]);
	print_fork(info, philo, get_cur_time() - info->start);
	do_eat(info, philo);
	while (get_cur_time() < philo->end_eat)
		usleep(info->t_eat);
	philo->eat++;
	if (info->must_eat == philo->eat)
	{
		pthread_mutex_lock(&info->full_check);
		info->full++;
		pthread_mutex_unlock(&info->full_check);
	}
	pthread_mutex_unlock(&info->forks[philo->first]);
	pthread_mutex_unlock(&info->forks[philo->second]);
}

void	do_eat(t_info *info, t_philo *philo)
{
	long	time;

	time = get_cur_time();
	philo->end_eat = time + info->t_eat;
	philo->starve = time + info->t_die;
	print_eat(info, philo, time - info->start);
}

void	do_sleep(t_info *info, t_philo *philo)
{
	long	time;

	time = get_cur_time();
	philo->end_sleep = time + info->t_sleep;
	print_sleep(info, philo, time - info->start);
	while (get_cur_time() < philo->end_sleep)
		usleep(info->t_sleep);
}

void	do_think(t_info *info, t_philo *philo)
{
	print_think(info, philo, get_cur_time() - info->start);
}
