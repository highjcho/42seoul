/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:04:13 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/01 14:26:58 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*into_a(char	*a, int n, int	last)
{
	last -= 1;
	if (n == -2147483648)
	{
		a[last] = '8';
		last -= 1;
		n /= 10;
	}
	if (n == -0)
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

char	*ft_itoa(int	n)
{
	char	*a;
	int		a_len;
	int		num;

	num = n;
	if (n <= 0)
		a_len = 1;
	else
		a_len = 0;
	while (num != 0)
	{
		num /= 10;
		a_len++;
	}
	a = (char *)ft_calloc((a_len + 1), sizeof(char));
	if (!a)
		return (0);
	return (into_a(a, n, a_len));
}
