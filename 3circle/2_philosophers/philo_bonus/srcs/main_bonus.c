/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:59:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/12 19:19:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

static int	starve_check(t_info *info)
{
	t_philo	philo;
	long	time;
	int		i;

	i = -1;
	while (++i < info->count)
	{
		philo = info->philos[i];
		time = get_cur_time();
		if (philo.starve != 0 && time > philo.starve)
		{
			pthread_mutex_lock(&info->print);
			info->play = FALSE;
			usleep(1000);
			printf("%s%ld %d died\n", DIE, time - info->start, philo.id);
			return (FALSE);
		}
	}
	return (TRUE);
}

static int	check_status(t_info *info)
{
	while (info->play)
	{
		if (!starve_check(info))
			return (FALSE);
		if (info->full == info->count)
		{
			info->play = FALSE;
			return (FALSE);
		}
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac < 5)
		return (0);
	info = malloc(sizeof(t_info));
	if (!init_info(&info, av))
		return(0);
	if (!make_mutex(&info))
		return (0);
	if (!make_thread(&info))
		return (0);
	if (!check_status(&info))
		detach_thread(&info, info->count);
	destroy_all(&info);
	return (0);
}
