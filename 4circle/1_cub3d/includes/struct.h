/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:31:48 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/08 19:09:54 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	plane;
	t_vector	dir;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_map
{
	int		has_info;
	int		width;
	int		height;
	int		floor;
	int		ceil;
	char	**map;
	char	**tex_files;
	int		start;
	int		end;
	int		player;
	char	start_dir;
	t_img	texture[4];
}	t_map;

typedef struct s_args
{
	double	cam_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	perp_wall;
	int		hit;
	int		side;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_args;

typedef struct s_info
{
	t_map		*map;
	t_player	*player;
	void		*mlx;
	void		*window;
	t_img		*img;
}	t_info;

#endif
