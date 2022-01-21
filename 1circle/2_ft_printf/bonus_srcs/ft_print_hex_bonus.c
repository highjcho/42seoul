/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:55:11 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/19 16:55:12 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	fill_number(char *result, unsigned int num, int *last, int *len)
{
	static char	hex_chars[16] = "0123456789abcdef";

	while (num > 0)
	{
		result[*last] = hex_chars[num % 16];
		num /= 16;
		(*last)--;
		(*len)++;
	}
}

static void	convert(char *result, unsigned int num, int last, t_sett *sett)
{
	int		len;

	len = 0;
	if (num == 0 && sett->precision != 0)
	{
		len++;
		result[last] = '0';
		last--;
	}
	fill_number(result, num, &last, &len);
	fill_zero(result, sett, &last, &len);
	if (sett->flag & FLAG_SIGN)
	{
		result[last--] = 'x';
		result[last--] = '0';
	}
	while (last >= 0)
		result[last--] = ' ';
}

static char	*ft_htoa(unsigned int n, int min, t_sett *sett, int *count)
{
	int				size;
	unsigned int	temp;
	char			*result;

	size = 0;
	if (n == 0)
		size++;
	else if (sett->flag & FLAG_SIGN)
		size += 2;
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
	convert(result, n, size - 1, sett);
	return (result);
}

static void	ft_to_upper(char *result, t_sett *sett, int count)
{
	if (sett->flag & FLAG_UPPER)
	{
		while (--count >= 0)
		{
			if ('a' <= result[count] && result[count] <= 'z')
				result[count] -= 32;
		}
	}
}

int	print_hex(va_list ap, t_sett *sett)
{
	unsigned int	val;
	int				min;
	int				count;
	char			*result;

	val = va_arg(ap, int);
	if (val == 0 && sett->precision == 0 && sett->width == 0)
		return (0);
	if (val != 0 && sett->flag & FLAG_HASH)
		sett->flag |= FLAG_SIGN;
	if (sett->width > sett->precision)
		min = sett->width;
	else
	{
		min = sett->precision;
		if (sett->flag & FLAG_SIGN)
			min += 2;
	}
	result = ft_htoa(val, min, sett, &count);
	if (result == NULL)
		return (-1);
	if (sett->flag & FLAG_LEFT)
		left_justify(result, count);
	ft_to_upper(result, sett, count);
	return (write_and_return(result, count));
}
