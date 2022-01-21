/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:28:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/05 10:30:34 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		rv;

	va_start(ap, s);
	rv = 0;
	while (*s)
	{
		if (*s != '%')
			s = ft_print_o(s, &rv);
		else
		{
			rv += find_f(*++s, ap);
			s++;
		}
	}
	va_end(ap);
	return (rv);
}

int	find_f(char c, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == 'x' || c == 'X')
		return (f_int(va_arg(ap, int), c));
	else if (c == 's')
		return (f_str(va_arg(ap, char *)));
	else if (c == 'p')
		return (f_addr(va_arg(ap, long)));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (-1);
}

int	f_int(int arg, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_itoa(arg));
	else if (c == 'u')
		return (ft_u_itoa(arg));
	else if (c == 'x' || c == 'X')
		return (ft_convert_hexa(arg, c));
	write(1, &arg, 1);
	return (1);
}

int	f_str(char *arg)
{
	if (arg == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_print_f(arg, 0));
}

int	f_addr(unsigned long arg)
{
	const char	*hexa = "0123456789abcdef";
	char		a[17];
	int			i;

	write (1, "0x", 2);
	if (arg == 0)
	{
		write (1, "0", 1);
		return (3);
	}
	i = 17;
	while (arg != 0)
	{
		a[i] = hexa[arg % 16];
		arg /= 16;
		i--;
	}
	write (1, a + i + 1, 17 - i);
	return (19 - i);
}
