/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:55:51 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/21 20:11:20 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	int				id;
	int				alive;
	long			end_eat;
	long			end_sleep;
	long			starve;
	pthread_t		philo;
}	t_philo;

typedef struct	s_info
{
	int				count;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				id;
	long			start;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_info;

# define TRUE 1
# define FALSE 0

// void	*set_time(void *arg);
int		do_task(t_info *info);
long	get_cur_time();
int		ft_atoi(char *s);

#endif