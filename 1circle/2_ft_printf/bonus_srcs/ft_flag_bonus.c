/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:52:09 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/19 16:54:40 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <limits.h>

static char	*get_flags(char *s, t_sett *sett)
{
	int	loop;

	loop = 1;
	while (loop)
	{
		if (*s == '0')
			sett->flag |= FLAG_ZERO;
		else if (*s == '-')
			sett->flag |= FLAG_LEFT;
		else if (*s == '+')
			sett->flag |= FLAG_PLUS;
		else if (*s == ' ')
			sett->flag |= FLAG_SPACE;
		else if (*s == '#')
			sett->flag |= FLAG_HASH;
		else
			break ;
		s++;
	}
	return (s);
}

static int	ft_atoi(char **s_ptr)
{
	long	result;
	long	prev;
	char	*str;

	str = *s_ptr;
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		prev = result;
		result = result * 10 + *str - '0';
		if (prev != result / 10)
			return ((int)LONG_MAX);
		str++;
	}
	*s_ptr = str;
	return ((int)(result));
}

static char	*get_width_and_precision(char *s, t_sett *sett)
{
	sett->width = ft_atoi(&s);
	if (*s == '.')
	{
		sett->flag |= FLAG_PRECISION;
		s++;
		sett->precision = ft_atoi(&s);
	}
	return (s);
}

static void	complete_flag(t_sett *sett)
{
	if (sett->flag & FLAG_LEFT || sett->flag & FLAG_PRECISION)
		sett->flag &= ~FLAG_ZERO;
	if (sett->flag & FLAG_PLUS)
		sett->flag &= ~FLAG_SPACE;
}

char	*get_setting(char *s, t_sett *sett)
{
	sett->flag = 0;
	sett->width = 0;
	sett->precision = 1;
	s = get_flags(s, sett);
	s = get_width_and_precision(s, sett);
	complete_flag(sett);
	return (s);
}
