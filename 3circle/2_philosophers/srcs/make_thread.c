/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:44:21 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/02 21:04:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	make_forks(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			destroy_forks(info, i - 1);
			printf("mutex init fail\n"); // 에러처리, 만든 부분까지
			return (FALSE);
		}
	}
	return (TRUE);
}

void destroy_forks(t_info *info, int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
		pthread_mutex_destroy(&info->forks[i]);
}

int	make_even_philos(t_info *info)
{
	int	i;

	i = 0;
	while (++i < info->count)
	{
		info->id = i;
		if (pthread_create(&(info->philos[i].philo), NULL, start_philo, info) != 0)
		{
			printf("thread create fail\n");
			return (FALSE);
		}
		i++;
		usleep(5);
	}
	return (TRUE);
}

int	make_odd_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
	{
		info->id = i;
		if (pthread_create(&(info->philos[i].philo), NULL, start_philo, info) != 0)
		{
			printf("thread create fail\n");
			return (FALSE);
		}
		i++;
		usleep(5);
	}
	return (TRUE);
}