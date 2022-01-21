/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:33:33 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/05 16:57:45 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hexa(unsigned int n, char c)
{
	const char	*hexa = "0123456789abcdef";
	char		a[18];
	int			i;

	i = 17;
	a[17] = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n != 0)
	{
		a[i] = hexa[n % 16];
		n /= 16;
		i--;
	}
	if (c == 'X')
		ft_toupper(a + i + 1);
	write(1, a + i + 1, 17 - i);
	return (17 - i);
}

char	*ft_print_o(const char *s, int *rv)
{
	int	len;

	len = 0;
	while (*s != '%' && *s)
	{
		len++;
		s++;
	}
	write(1, s - len, len);
	*rv += len;
	return ((char *)s);
}

int	ft_print_f(char *s, int flag)
{
	size_t	len;

	len = ft_strlen(s);
	write(1, s, len);
	if (flag == 1)
		free(s);
	return ((int)len);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_toupper(char	*s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}
