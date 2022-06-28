/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:25:43 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/28 19:47:29 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->forks[philo->id]);
	pthread_mutex_lock(&info->forks[(philo->id + 1) % info->count]);
	do_eat(info, philo);
	while (get_cur_time() < philo->end_eat)
		usleep(info->t_eat * 10);
	pthread_mutex_unlock(&info->forks[philo->id]);
	pthread_mutex_unlock(&info->forks[(philo->id + 1) % info->count]);
}


void	do_eat(t_info *info, t_philo *philo)
{
	long	time;
	
	time = get_cur_time();
	philo->end_eat = time + info->t_eat;
	philo->starve = time + info->t_die;
	printf("%ld %d is eating(e_eat: %ld, starve: %ld)\n", time - info->start, philo->id, philo->end_eat - info->start, philo->starve - info->start);
}

void	do_sleep(t_info *info, t_philo *philo)
{
	long	time;
	
	if (philo->alive == FALSE)
		return ;
	time = get_cur_time();
	philo->end_sleep = time + info->t_sleep;
	printf("%ld %d is sleeping(wake: %ld)\n", time - info->start, philo->id, philo->end_sleep - info->start);
	while (get_cur_time() < philo->end_sleep)
	{
		usleep(info->t_sleep * 10);
		if (get_cur_time() > philo->starve)
		{
			philo->alive = FALSE;
			break;
		}
	}
}

void	do_think(t_info *info, t_philo *philo)
{
	long	time;
	
	(void)info; // think에서 뮤텍스가 풀렸는지 확인할 수 있나? 그냥 프린트만 찍고 지나가야 하나?
	if (philo->alive == FALSE)
		return ;
	time = get_cur_time();
	printf("%ld %d is thinking\n", time - info->start, philo->id);
	if (get_cur_time() > philo->starve)
		philo->alive = FALSE;
}