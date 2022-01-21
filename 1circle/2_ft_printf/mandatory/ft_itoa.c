/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:04:13 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/05 16:57:15 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*into_a(char *a, long n, int last)
{
	if (n == 0)
	{
		*a = '0';
		return (a);
	}
	if (n < 0)
	{
		a[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		a[last] = n % 10 + '0';
		last--;
		n /= 10;
	}
	return (a);
}

int	ft_itoa(int n)
{
	char	*a;
	int		a_len;
	long	tmp;

	tmp = n;
	a_len = 0;
	if (tmp <= 0)
		a_len = 1;
	while (tmp != 0)
	{
		tmp /= 10;
		a_len++;
	}
	a = (char *)ft_calloc((a_len + 1), sizeof(char));
	if (!a)
		return (0);
	a = into_a(a, n, a_len - 1);
	return (ft_print_f(a, 1));
}

static char	*into_u_a(char	*a, unsigned int n, int	last)
{
	if (n == 0)
	{
		*a = '0';
		return (a);
	}
	while (n != 0)
	{
		a[last] = n % 10 + '0';
		last--;
		n /= 10;
	}
	return (a);
}

int	ft_u_itoa(unsigned int n)
{
	char			*a;
	int				a_len;
	unsigned int	tmp;

	tmp = n;
	a_len = 0;
	if (tmp <= 0)
		a_len = 1;
	while (tmp != 0)
	{
		tmp /= 10;
		a_len++;
	}
	a = (char *)ft_calloc((a_len + 1), sizeof(char));
	if (!a)
		return (0);
	a = into_u_a(a, n, a_len - 1);
	return (ft_print_f(a, 1));
}