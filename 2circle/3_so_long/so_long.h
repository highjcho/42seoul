#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <sys/errno.h> // 사용 가능한가?
# include "libft/libft.h"

# define W			13
# define A			0
# define S			1
# define D			2
# define ESC		53
# define PRESS_KEY	3
# define MOUSE_EXIT	17
# define UP			6
# define DOWN		7
# define LEFT		8
# define RIGHT		9
# define BUFFER_SIZE 1024

typedef struct	s_p
{
	int	p;
	int	x;
	int	y;
	int	move;
}	t_p;

typedef struct	s_img
{
	void	*p;
	void	*wall;
	void	*path;
	void	*item;
	void	*exit;
}	t_img;

typedef struct	s_game
{
	t_p		p;
	int		exit;
	int		item;
	char	**map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_game;

void	check_map(t_game *game);
char	*get_next_line(int fd);
char	**ft_split(t_game *game, char const *s, char c);
void	print_map(t_game *game);
int		play_game(int key_code, t_game *game);
void	print_new_p(t_game *game, t_game *img, int flag, int new_r);
void	double_free(t_game *game);
void	error_handler(char *msg, int err);
int	exit_game(t_game *game);

#endif