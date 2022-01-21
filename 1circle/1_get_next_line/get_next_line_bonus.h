/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:54:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/20 15:55:00 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define FD_MAX 256

char	*get_next_line(int fd);
char	*make_line(char *buf, char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strncpy(char *dst, char *src, size_t dstsize);
char	*ft_strchr(char *s);
char	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t len);
void	ft_memmove(void *dst, void *src, size_t len);
size_t	ft_len(char *s);

#endif
