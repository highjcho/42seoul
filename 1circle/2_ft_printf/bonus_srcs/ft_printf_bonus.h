/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:55:57 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/19 16:55:58 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FLAG_ZERO		1
# define FLAG_LEFT		2
# define FLAG_PLUS		4
# define FLAG_SPACE		8
# define FLAG_HASH		16
# define FLAG_UPPER		32
# define FLAG_PRECISION	64
# define FLAG_SIGN		128

typedef struct s_sett
{
	int	flag;
	int	width;
	int	precision;
}			t_sett;

int		ft_printf(const char *s, ...);
char	*get_setting(char *s, t_sett *sett);
int		print_int(va_list ap, t_sett *sett);
int		print_u_int(va_list ap, t_sett *sett);
int		print_hex(va_list ap, t_sett *sett);
int		print_addr(va_list ap, t_sett *sett);
int		print_char(va_list ap, t_sett *sett);
int		print_str(va_list ap, t_sett *sett);
void	fill_zero(char *result, t_sett *sett, int *last, int *len);
void	left_justify(char *str, int len);
int		error_format(va_list ap, t_sett *sett);
int		write_and_return(char *result, int count);
#endif
