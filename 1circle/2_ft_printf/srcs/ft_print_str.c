/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:50:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/19 16:50:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_left(char *result, char *val, int len, int size)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		result[idx] = val[idx];
		idx++;
	}
	while (idx < size)
	{
		result[idx] = ' ';
		idx++;
	}
}

static void	fill_right(char *result, char *val, int len, int size)
{
	int	idx;

	idx = size - len;
	while (idx < size)
	{
		result[idx] = val[idx - (size - len)];
		idx++;
	}
	idx = 0;
	while (idx < size - len)
	{
		result[idx] = ' ';
		idx++;
	}
}

static int	get_size(char *val, t_sett *sett, int *len)
{
	int	size;

	*len = 0;
	while (val[*len])
		(*len)++;
	if (sett->flag & FLAG_PRECISION && sett->precision < *len)
		*len = sett->precision;
	size = *len;
	if (sett->width > size)
		size = sett->width;
	return (size);
}

int	print_str(va_list ap, t_sett *sett)
{
	int		len;
	int		size;
	char	*val;
	char	*result;

	val = va_arg(ap, char *);
	if (val == NULL)
		val = "(null)";
	size = get_size(val, sett, &len);
	if (size == 0)
		return (0);
	result = malloc(sizeof (char) * size);
	if (result == NULL)
		return (-1);
	if (sett->flag & FLAG_LEFT)
		fill_left(result, val, len, size);
	else
		fill_right(result, val, len, size);
	return (write_and_return(result, size));
}
