/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/22 16:52:19 by hyunjcho         ###   ########.fr       */
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
	// printf("thread: id: %d, start: %ld, starve: %ld\n", philo->id, info->start, philo->starve);
	while (philo->alive)
	{
		take_fork(info, philo);
		do_eat(info, philo); // 잇 전에 포크 집는 거 먼저 하기 // 
		do_sleep(info, philo);
		do_think(info, philo);
		if (get_cur_time() > philo->starve)
			philo->alive = FALSE; 
	}
	return (NULL);
}

static int	init_task(t_info *info, int count)
{
	int	check;

	info->start = get_cur_time();
	if (!make_forks(info))
		return (FALSE);
	if (!make_odd_philos(info))
	{
		make
		return (FALSE);
	}
	if (!make_)
	while (++i < count) // 뮤텍스 이닛 따로 처리하고 쓰레드 크리에이트를 짝홀로 나누기
	{
		info->id = i;
		if (pthread_create(&(info->philos[i].philo), NULL, start_philo, info) != 0)
		{
			printf("thread create fail\n");
			return (FALSE);
		}
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			printf("mutex init fail\n");
			return (FALSE);
		}
		usleep(5);
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
	return (0);
}