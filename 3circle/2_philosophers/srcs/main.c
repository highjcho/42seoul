/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/20 21:34:20 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	init_info(t_info *info, char **av)
{
	info->philos = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->must_eat = ft_atoi(av[5]);
	if (info->philos == -1 || info->t_die == -1 || info->t_eat == -1 || \
		info->t_sleep == -1 || info->must_eat == -1)
		return (FALSE);
	return (TRUE);
}

void	*print_some(void *name)
{
	pid_t pid;
	unsigned long tid;
	char	*thread_name;

	pid = getpid();
	tid = (unsigned long)pthread_self();
	thread_name = (char *)name;
	printf("thread name: %s, pid: %u, tid: %lu\n", thread_name, pid, tid);
	usleep(1000000);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info			info;
	pthread_t		*philos;
	pthread_mutex_t *forks;

	int	i;
	char	*name[3];
	int		status;

	if (ac < 5)
		return (0);
	if (!init_info(&info, av))
		return (0);
	i = -1;
	philos = malloc(sizeof(pthread_t) * info.philos);
	forks = malloc(sizeof(pthread_mutex_t) * info.philos);
	if (!philos || !forks)
		return (0);
	while (++i < info.philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("mutex init fail\n");
			return (0);
		}
	}
	name[0] = "thread1";
	name[1] = "thread2";
	name[2] = "thread3";
	i = -1;
	while (++i < info.philos)
	{
		if (pthread_create(&philos[i], NULL, print_some, name[i]) != 0)
		{
			printf("thread create fail\n");
			return (0);
		}
	}
	print_some("main");
	pthread_join(philos[0], (void **)&status);
	printf("1 - %d\n", status);
	pthread_join(philos[1], (void **)&status);
	printf("2 - %d\n", status);
	pthread_join(philos[2], (void **)&status);
	printf("3 - %d\n", status);
	return (0);
}