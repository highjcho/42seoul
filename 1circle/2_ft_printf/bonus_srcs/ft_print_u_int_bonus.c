/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:55:34 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/19 16:55:35 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	fill_number(char *result, unsigned int num, int *last, int *len)
{
	while (num > 0)
	{
		result[*last] = num % 10 + '0';
		num /= 10;
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
	while (last >= 0)
		result[last--] = ' ';
}

static char	*ft_u_itoa(unsigned int n, int min, t_sett *sett, int *count)
{
	int				size;
	unsigned int	temp;
	char			*result;

	size = 0;
	if (n == 0)
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

int	print_u_int(va_list ap, t_sett *sett)
{
	unsigned int	val;
	int				min;
	int				count;
	char			*result;

	val = (unsigned int)va_arg(ap, int);
	if (val == 0 && sett->precision == 0 && sett->width == 0)
		return (0);
	if (sett->width > sett->precision)
		min = sett->width;
	else
		min = sett->precision;
	result = ft_u_itoa(val, min, sett, &count);
	if (result == NULL)
		return (-1);
	if (sett->flag & FLAG_LEFT)
		left_justify(result, count);
	return (write_and_return(result, count));
}
