/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:57:15 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/12 17:45:08 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	make_forks(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			destroy_forks(info, i - 1);
			return (print_error("mutex init fail\n"));
		}
	}
	return (TRUE);
}

int	make_mutex(t_info *info)
{
	if (!make_forks(info))
		return (FALSE);
	if (pthread_mutex_init(&(info->done), NULL) != 0)
	{
		destroy_forks(info, info->count);
		return (print_error("mutex init fail\n"));
	}
	if (pthread_mutex_init(&(info->full_check), NULL) != 0)
	{
		destroy_forks(info, info->count);
		pthread_mutex_destroy(&info->done);
		return (print_error("mutex init fail\n"));
	}
	if (pthread_mutex_init(&(info->print), NULL) != 0)
	{
		destroy_forks(info, info->count);
		pthread_mutex_destroy(&info->done);
		pthread_mutex_destroy(&info->full_check);
		return (print_error("mutex init fail\n"));
	}
	return (TRUE);
}

void	destroy_forks(t_info *info, int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
		pthread_mutex_destroy(&info->forks[i]);
}

void	destroy_all(t_info *info)
{
	destroy_forks(info, info->count);
	pthread_mutex_destroy(&info->done);
	pthread_mutex_destroy(&info->full_check);
	// pthread_mutex_destroy(&info->print);
	free(info->philos);
	free(info->forks);
}
