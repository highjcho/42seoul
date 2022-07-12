/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:57:08 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/12 19:19:34 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

static void	init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < info->count)
	{
		philo->id = i + 1;
		philo->eat = 0;
		if (philo->id % 2 == 0)
		{
			philo->first = (i + 1) % info->count;
			philo->second = i;
		}
		else
		{
			philo->first = i;
			philo->second = (i + 1) % info->count;
		}
		philo->starve = 0;
		philo->info = info;
	}
}

static int allocate_arg(t_info *info)
{
	info->pid = malloc(sizeof(pid_t) * info->count);
	if (!info->philos)
		return (print_error("Initalize fail"));
	info->philos = malloc(sizeof(t_philo) * info->count);
	if (!info->philos)
	{
		free(info->pid);
		return (print_error("Initalize fail"));
	}
	info->forks = malloc(sizeof(pthread_mutex_t) * info->count);
	if (!info->forks)
	{
		free(info->pid);
		free(info->philos);
		return (print_error("Initalize fail"));
	}
}

int	init_info(t_info *info, char **av)
{
	info->count = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->must_eat = ft_atoi(av[5]);
	info->full = 0;
	info->play = TRUE;
	if (info->count < 1 || info->t_die < 1 || info->t_eat == -1 || \
		info->t_sleep == -1 || info->must_eat == 0)
		return (print_error("Invalid arguments"));
	if (!allocate_arg(info))
		return (FALSE);
	init_philo(info);
	return (TRUE);
}
