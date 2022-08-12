/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:30:51 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/08 17:55:16 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "struct.h"
# include "init.h"
# include "map.h"
# include "play.h"
# include "utils.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53

# define PRESS_KEY	2
# define MOUSE_EXIT	17

# define SCREEN_X	1280
# define SCREEN_Y	960

# define TEX_WIDTH	64
# define TEX_HEIGHT	64

# define NORTH	0
# define SOUTH	1
# define EAST	2
# define WEST	3

# define MOVE_SPEED	0.213
# define ROT_SPEED	0.05

# define HIT_X	0
# define HIT_Y	1

# define COLOR_WALL		0xcdc2ae
# define COLOR_PLAYER	0xf47c7c
# define COLOR_EMPTY	0xfbecbb

# define TRUE	1
# define FALSE	0

#endif
