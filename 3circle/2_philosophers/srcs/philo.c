/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:25:43 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/22 15:46:49 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	do_eat(t_info *info, t_philo *philo)
{
	long	time;
	
	time = get_cur_time();
	philo->end_eat = time + info->t_eat;
	philo->starve = time + info->t_die;
	printf("%ld %d is eating\n", time - info->start, philo->id);
	usleep(info->t_eat * 1000);
}

void	do_sleep(t_info *info, t_philo *philo)
{
	long	time;
	
	time = get_cur_time();
	philo->end_sleep = time + info->t_sleep;
	printf("%ld %d is sleeping\n", time - info->start, philo->id);
	usleep(info->t_sleep * 1000);
}

void	do_think(t_info *info, t_philo *philo)
{
	long	time;
	long	must_awake;
	
	(void)info; // think에서 뮤텍스가 풀렸는지 확인할 수 있나? 그냥 프린트만 찍고 지나가야 하나?
	time = get_cur_time();
	printf("%ld %d is thinking\n", time - info->start, philo->id);
}