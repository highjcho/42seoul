/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:44:21 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/22 16:50:31 by hyunjcho         ###   ########.fr       */
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
			printf("mutex init fail\n");
			return (FALSE);
		}
	}
	return (TRUE);
}

int	make_odd_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
	{
		if (i % 2 == 0)
		{
			info->id = i;
			if (pthread_create(&(info->philos[i].philo), NULL, start_philo, info) != 0)
			{
				printf("thread create fail\n");
				return (FALSE);
			}
		}
	}
}

int	make_even_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
	{
		if (i % 2 == 0)
		{
			info->id = i;
			if (pthread_create(&(info->philos[i].philo), NULL, start_philo, info) != 0)
			{
				printf("thread create fail\n");
				return (FALSE);
			}
		}
	}
}