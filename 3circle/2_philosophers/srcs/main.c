/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/02 21:15:11 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*start_philo(void	*arg) // 반환값을 받아서 쓸게 없음;고민필
{
	t_info	*info;
	t_philo	*philo;
	
	info = (t_info *)arg;
	philo = &info->philos[info->id];
	philo->id = info->id + 1;
	philo->alive = TRUE;
	philo->starve = info->start + info->t_die;
	while (philo->alive)
	{
		take_fork(info, philo);
		do_sleep(info, philo);
		do_think(info, philo);
	}
	return (NULL);
}

static int	init_task(t_info *info)
{
	info->start = get_cur_time();
	if (!make_forks(info))
		return (FALSE);
	if (!make_even_philos(info))
	{
		destroy_forks(info, info->count);
		return (FALSE);
	}
	if (!make_odd_philos(info))
	{
		destroy_forks(info, info->count);
		return (FALSE); // 실패 시 쓰레드 없애는 거 반복문 돌면서 어케할지 생각 필요
	}
	return (TRUE);
}

static int	init_info(t_info *info, char **av)
{
	info->count = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->must_eat = ft_atoi(av[5]);
	info->full = 0;
	if (info->count < 1 || info->t_die < 1 || info->t_eat == -1 || \
		info->t_sleep == -1 || info->must_eat == 0 || info->must_eat == -1)
		return (FALSE);
	info->philos = malloc(sizeof(t_philo) * info->count);
	if (!info->philos)
		return (FALSE);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->count);
	if (!info->forks)
	{
		free(info->philos);
		return (FALSE);
	}
	return (TRUE);
}

static void	all_stop(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count)
		info->philos[i].alive = FALSE;
}

static int	check_status(t_info *info)
{
	t_philo	philo;
	long	time;
	int		i;

	while (1)
	{
		i = -1;
		while (++i < info->count)
		{
			philo = info->philos[i];
			if (get_cur_time() > philo.starve)
			{
				time = get_cur_time() - info->start;
				printf("%ld %d died\n", time, philo.id);
				all_stop(info);
				return (FALSE);
			}
		}
		if (info->full == info->count)
		{
			all_stop(info);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5)
		return (0);
	if (!init_info(&info, av))
		return (0);
	if (!init_task(&info))
		return (0);
	if (!check_status(&info))
	{
		int i = -1;
		while (++i < info.count)
			pthread_detach(info.philos[i].philo);
	}
	return (0);
}