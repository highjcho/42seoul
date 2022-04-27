#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <sys/errno.h> // 사용 가능한가?
# include "libft/libft.h"

# define W		13
# define A		0
# define S		1
# define D		2
# define ESC	53
# define BUFFER_SIZE 1024

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
	int		p;
	int		p_x;
	int		p_y;
	int		exit;
	int		item;
	char	**map;
	int		width;
	int		height;
	t_img	img;
}	t_game;

void	check_map(t_game *game);
char	*get_next_line(int fd);
char	**ft_split(t_game *game, char const *s, char c);
void	print_map(t_game *game, void *mlx, void *win);
void	error_handler(char *msg, int err);

#endif