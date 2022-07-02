/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:25:43 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/02 21:22:28 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->forks[philo->id - 1]);
	print_philo(philo, get_cur_time() - info->start, "has taken a fork");
	pthread_mutex_lock(&info->forks[philo->id % info->count]);
	print_philo(philo, get_cur_time() - info->start, "has taken a fork");
	do_eat(info, philo);
	while (get_cur_time() < philo->end_eat)
		usleep(info->t_eat * 1);
	pthread_mutex_unlock(&info->forks[philo->id - 1]);
	pthread_mutex_unlock(&info->forks[philo->id % info->count]);
}


void	do_eat(t_info *info, t_philo *philo)
{
	long	time;
	
	time = get_cur_time();
	philo->end_eat = time + info->t_eat;
	philo->starve = time + info->t_die;
	print_philo(philo, time - info->start, "is eating");
	philo->eat++;
	if (info->must_eat > 0 && info->must_eat == philo->eat)
	{
		info->full++;
		philo->alive = FALSE;
	}
}

void	do_sleep(t_info *info, t_philo *philo)
{
	long	time;
	
	if (!philo->alive)
		return ;
	time = get_cur_time();
	philo->end_sleep = time + info->t_sleep;
	print_philo(philo, time - info->start, "is sleeping");
	while (get_cur_time() < philo->end_sleep)
		usleep(info->t_sleep * 1);
}

void	do_think(t_info *info, t_philo *philo)
{
	long	time;
	
	time = get_cur_time();
	print_philo(philo, time - info->start, "is thinking");
}