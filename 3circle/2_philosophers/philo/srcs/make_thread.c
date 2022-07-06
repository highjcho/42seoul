/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:44:21 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/05 17:17:14 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	make_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
	{
		info->id = i;
		if (pthread_create(&(info->philos[i].philo), NULL, \
			start_philo, info) != 0)
			return (print_error("create pthread fail"));
		info->make++;
		usleep(5);
	}
	return (TRUE);
}

static void	*set_start_time(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	pthread_mutex_lock(&info->done);
	while (info->make < info->count)
		continue ;
	info->start = get_cur_time();
	pthread_mutex_unlock(&info->done);
	return (NULL);
}

int	make_thread(t_info *info)
{	
	if (pthread_create(&info->check, NULL, set_start_time, info) != 0)
	{
		destroy_all(info);
		return (print_error("create pthread fail"));
	}
	pthread_detach(info->check);
	usleep(10);
	if (!make_philos(info))
	{
		detach_thread(info, info->make - 2);
		destroy_all(info);
		return (FALSE);
	}
	return (TRUE);
}

void	detach_thread(t_info *info, int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
	{
		pthread_detach(info->philos[i].philo);
		info->die++;
	}
}
