/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:57:08 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/04 19:03:38 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < info->count)
	{
		philo = &(info->philos[i]);
		philo->id = i + 1;
		philo->eat = 0;
		if (i % 2 != 0)
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
	info->make = 0;
	info->play = TRUE;
	if (info->count < 1 || info->t_die < 1 || info->t_eat == -1 || \
		info->t_sleep == -1 || info->must_eat == 0)
		return (print_error("Invalid arguments"));
	info->philos = malloc(sizeof(t_philo) * info->count);
	if (!info->philos)
		return (print_error("Initalize fail"));
	info->forks = malloc(sizeof(pthread_mutex_t) * info->count);
	if (!info->forks)
	{
		free(info->philos);
		return (print_error("Initalize fail"));
	}
	init_philo(info);
	return (TRUE);
}
