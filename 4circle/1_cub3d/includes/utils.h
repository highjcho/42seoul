/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:31:58 by heehkim           #+#    #+#             */
/*   Updated: 2022/08/06 22:32:08 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

# define BUFFER_SIZE 2048

// get_next_line.c
char		*get_next_line(int fd);

// utils.c
int			ft_isspace(char c);
void		exit_error(char *msg);

#endif
