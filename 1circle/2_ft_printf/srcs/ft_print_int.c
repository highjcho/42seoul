/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:50:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/19 16:50:07 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_number(char *result, long num, int *last, int *len)
{
	while (num > 0)
	{
		result[*last] = num % 10 + '0';
		num /= 10;
		(*last)--;
		(*len)++;
	}
}

static void	convert(char *result, long num, int last, t_sett *sett)
{
	int		len;
	char	sign;

	len = 0;
	sign = '+';
	if (num < 0)
	{
		sign = '-';
		num *= -1;
	}
	if (num == 0 && sett->precision != 0)
	{
		len++;
		result[last] = '0';
		last--;
	}
	fill_number(result, num, &last, &len);
	fill_zero(result, sett, &last, &len);
	if (sign == '-' || sett->flag & FLAG_PLUS)
		result[last--] = sign;
	else if (sett->flag & FLAG_SPACE)
		result[last--] = ' ';
	while (last >= 0)
		result[last--] = ' ';
}

static char	*ft_itoa(int n, int min, t_sett *sett, int *count)
{
	int		size;
	int		temp;
	char	*result;

	size = 0;
	if (n == 0 || sett->flag & FLAG_SIGN)
		size++;
	temp = n;
	while (temp != 0)
	{
		size++;
		temp /= 10;
	}
	if (min > size)
		size = min;
	*count = size;
	result = malloc(sizeof (*result) * size);
	if (result == NULL)
		return (NULL);
	convert(result, n, size - 1, sett);
	return (result);
}

int	print_int(va_list ap, t_sett *sett)
{
	int		val;
	int		min;
	int		count;
	char	*result;

	val = va_arg(ap, int);
	if (val == 0 && sett->precision == 0 && sett->width == 0)
		return (0);
	if (val < 0 || sett->flag & FLAG_SPACE || sett->flag & FLAG_PLUS)
		sett->flag |= FLAG_SIGN;
	if (sett->width > sett->precision)
		min = sett->width;
	else
	{
		min = sett->precision;
		if (sett->flag & FLAG_SIGN)
			min++;
	}
	result = ft_itoa(val, min, sett, &count);
	if (result == NULL)
		return (-1);
	if (sett->flag & FLAG_LEFT)
		left_justify(result, count);
	return (write_and_return(result, count));
}
