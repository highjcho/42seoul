/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:49:33 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/19 16:49:35 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_number(char *result, unsigned long num, int *last)
{
	static char	hex_chars[16] = "0123456789abcdef";

	while (num > 0)
	{
		result[*last] = hex_chars[num % 16];
		num /= 16;
		(*last)--;
	}
}

static void	convert(char *result, unsigned long num, int last)
{
	if (num == 0)
		result[last--] = '0';
	fill_number(result, num, &last);
	result[last--] = 'x';
	result[last--] = '0';
	while (last >= 0)
		result[last--] = ' ';
}

static char	*ft_ptoa(unsigned long n, int min, int *count)
{
	int				size;
	unsigned long	temp;
	char			*result;

	size = 2;
	if (n == 0)
		size++;
	temp = n;
	while (temp != 0)
	{
		size++;
		temp /= 16;
	}
	if (min > size)
		size = min;
	*count = size;
	result = malloc(sizeof (*result) * size);
	if (result == NULL)
		return (NULL);
	convert(result, n, size - 1);
	return (result);
}

int	print_addr(va_list ap, t_sett *sett)
{
	unsigned long	val;
	int				count;
	char			*result;

	val = va_arg(ap, long);
	result = ft_ptoa(val, sett->width, &count);
	if (result == NULL)
		return (-1);
	if (sett->flag & FLAG_LEFT)
		left_justify(result, count);
	return (write_and_return(result, count));
}
