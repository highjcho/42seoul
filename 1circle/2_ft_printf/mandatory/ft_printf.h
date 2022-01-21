/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:31:58 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/05 10:32:00 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
char	*ft_print_o(const char *s, int *rv);
int		ft_print_f(char *s, int flag);
int		find_f(char c, va_list ap);
int		f_int(int arg, char c);
int		f_str(char *arg);
int		f_addr(unsigned long arg);
int		ft_itoa(int n);
int		ft_u_itoa(unsigned int n);
int		ft_convert_hexa(unsigned int n, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_toupper(char	*s);
size_t	ft_strlen(const char *str);

#endif
