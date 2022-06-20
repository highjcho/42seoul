/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:57:07 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/05 14:57:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/errno.h>
# include <mlx.h>
# include "../libft/libft.h"

# define W				13
# define A				0
# define S				1
# define D				2
# define ESC			53
# define PRESS_KEY		2
# define MOUSE_EXIT		17
# define UP				6
# define DOWN			7
# define LEFT			8
# define RIGHT			9
# define BUFFER_SIZE	1024
# define YELLOW			16770223

typedef struct s_p
{
	int	p;
	int	x;
	int	y;
	int	moves;
}	t_p;

typedef struct s_img
{
	void	*p;
	void	*w;
	void	*r;
	void	*i;
	void	*c;
	void	*e;
}	t_img;

typedef struct s_game
{
	t_p		p;
	int		exit;
	int		item;
	char	**map;
	void	*m;
	void	*w;
	int		wid;
	int		hei;
	char	*text;
	t_img	i;
}	t_game;

char	*get_next_line(int fd, char *s);
char	**ft_split(t_game *g, char const *s, char c);
void	check_rectangular(t_game *g, int wid, char *s1, char *s2);
void	check_map(t_game *g);
void	print_map(t_game *g);
int		play_game(int key_code, t_game *g);
int		force_quit(t_game *g);
void	change_exit(t_game *g);
void	print_moves(t_game *g);
void	print_new_p(t_game *g, int flag, int new_r);
void	map_free(t_game *g);
void	destroy_all(t_game *g);
void	map_error(t_game *g, char *msg);
void	error_free(char *msg, char *s1, char *s2, int err);
void	error_handler(char *msg, int err);

#endif
