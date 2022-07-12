/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:55:51 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/07/12 19:10:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo t_philo;

typedef struct s_info
{
	int				count;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				must_eat;
	int				full;
	int				make;
	int				play;
	long			start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	done;
	pthread_mutex_t	full_check;
	pthread_mutex_t	print;
	pthread_t		check;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				eat;
	int				first;
	int				second;
	long			end_eat;
	long			end_sleep;
	long			starve;
	pthread_t		philo;
	t_info			*info;
}	t_philo;



# define TRUE 1
# define FALSE 0
# define FORK "\033[0;36m"
# define EAT "\033[0;33m"
# define DIE "\033[0;31m"
# define SLEEP "\033[0;35m"
# define THINK "\033[0;32m"

int		init_info(t_info *info, char **av);
int		make_thread(t_info *info);
int		make_mutex(t_info *info);
void	*start_philo(void *arg);
void	take_fork(t_info *info, t_philo *philo);
void	do_eat(t_info *info, t_philo *philo);
void	do_sleep(t_info *info, t_philo *philo);
void	do_think(t_info *info, t_philo *philo);
void	destroy_forks(t_info *info, int cnt);
void	destroy_all(t_info *info);
void	detach_thread(t_info *info, int cnt);
void	print_fork(t_info *info, t_philo *philo, long time);
void	print_eat(t_info *info, t_philo *philo, long time);
void	print_sleep(t_info *info, t_philo *philo, long time);
void	print_think(t_info *info, t_philo *philo, long time);
void	join_thread(t_info *info, int cnt);
int		print_error(char *msg);
long	get_cur_time(void);
int		ft_atoi(char *s);

#endif