/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:12:41 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/13 17:09:32 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	find_c(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (TRUE);
	}
	return (FALSE);
}

int	check_key(char *key)
{
	int	i;

	if (!(ft_isalpha(key[0]) || key[0] == '_'))
		return (FALSE);
	i = 0;
	while (key[++i])
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
			return (FALSE);
	return (TRUE);
}

int	is_long(char *s)
{
	unsigned long long	ul;
	int					sign;
	int					tmp;

	ul = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		if (ft_isdigit(*s) == FALSE)
			return (FALSE);
		tmp = ul;
		ul = (*s - '0') + (ul * 10);
		if (tmp != ul / 10)
			return (FALSE);
		if ((ul > LONG_MAX && sign == 1) || (ul - 1 > LONG_MAX && sign == -1))
			return (FALSE);
		s++;
	}
	return (TRUE);
}

long long	ft_atol(char *s)
{
	long long	ul;
	int			sign;
	int			tmp;

	ul = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		tmp = ul;
		ul = (*s - '0') + (ul * 10);
		s++;
	}
	return (ul * sign);
}

int	a(char c)
{
	return (ft_isalpha(c));
}
