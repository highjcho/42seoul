/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/21 20:18:28 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	*set_time(void	*arg) // 반환값을 받아서 쓸게 없음;고민필
{
	t_info	*info;
	t_philo	*philo;
	
	info = (t_info *)arg;
	philo = &info->philos[info->id];
	philo->id = info->id + 1;
	philo->starve = info->start + info->t_die;
	philo->alive = TRUE;
	// printf("thread: id: %d, start: %ld, starve: %ld\n", philo->id, info->start, philo->starve);
	while (philo->alive)
	{
		do_eat(); // do_ea
		do_sleep();
		do_think();
	}
	return (NULL);
}

static int	init_task(t_info *info, int count)
{
	int	i;

	info->start = get_cur_time();
	i = -1;
	while (++i < count)
	{
		info->id = i;
		if (pthread_create(&(info->philos[i].philo), NULL, set_time, info) != 0)
		{
			printf("thread create fail\n");
			return (FALSE);
		}
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			printf("mutex init fail\n");
			return (FALSE);
		}
		// usleep(10);
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
	if (info->count == -1 || info->t_die == -1 || info->t_eat == -1 || \
		info->t_sleep == -1 || info->must_eat == -1)
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

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5)
		return (0);
	if (!init_info(&info, av))
		return (0);
	if (!init_task(&info, info.count))
	{
		free(info.philos);
		free(info.forks);
		return (0);
	}
	// usleep(500000);
	// do_task(&info);
	// monitor -> 각 철학자별로 죽었는지
	int i;
	int	status = 0;
	i = -1;
	while (++i < info.count)
		pthread_join(info.philos[i].philo, (void *)&status);
	i = -1;
	while (++i < info.count)
		printf("%d philo: starve : %ld, id: %d\n", i, info.philos[i].starve, info.philos[i].id);
	return (0);
}