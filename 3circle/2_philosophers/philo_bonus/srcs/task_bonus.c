/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:25:43 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/06 22:18:05 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->forks[philo->first]);
	print_philo(info, philo, get_cur_time() - info->start, 0);
	pthread_mutex_lock(&info->forks[philo->second]);
	print_philo(info, philo, get_cur_time() - info->start, 0);
	do_eat(info, philo);
	while (get_cur_time() < philo->end_eat)
		usleep(info->t_eat * 1);
	pthread_mutex_unlock(&info->forks[philo->first]);
	pthread_mutex_unlock(&info->forks[philo->second]);
}

void	do_eat(t_info *info, t_philo *philo)
{
	long	time;

	time = get_cur_time();
	philo->end_eat = time + info->t_eat;
	philo->starve = time + info->t_die;
	print_philo(info, philo, time - info->start, 1);
	philo->eat++;
	if (info->must_eat == philo->eat)
	{
		pthread_mutex_lock(&info->full_check);
		info->full++;
		pthread_mutex_unlock(&info->full_check);
	}
}

void	do_sleep(t_info *info, t_philo *philo)
{
	long	time;

	time = get_cur_time();
	philo->end_sleep = time + info->t_sleep;
	print_philo(info, philo, time - info->start, 2);
	while (get_cur_time() < philo->end_sleep)
		usleep(info->t_sleep * 1);
}

void	do_think(t_info *info, t_philo *philo)
{
	print_philo(info, philo, get_cur_time() - info->start, 3);
}
