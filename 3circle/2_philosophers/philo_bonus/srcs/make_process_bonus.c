/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:44:21 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/12 19:44:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

static int	make_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
	{
		if (pthread_create(&(info->philos[i].philo), NULL, \
			start_philo, &info->philos[i]) != 0)
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

int	make_process(t_info *info)
{	
	int	i;

	i = -1;
	while (++i < info->count)
	{
		info->pid[i] = fork();
		if (info->pid[i] < 0)
		{
			kill_process(info, i);
			exit(EXIT_FAILURE);
		}
		if (info->pid[i] == 0)
			do_philo();
	}
	if (waitpid(-1, )) // 누군가 죽으면
	{

	}
	return (TRUE);
}

void	kill_process(t_info *info, int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
		kill(info->pid[i], SIGINT);
