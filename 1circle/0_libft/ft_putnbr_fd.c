/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:31:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/01 16:55:31 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	into_n(int n, int fd)
{
	int	check_n;

	check_n = 1;
	if (n < 0 && n / 10 == 0)
		ft_putchar_fd('-', fd);
	if (n < 0)
		check_n = -1;
	if (n / 10 != 0)
		into_n(n / 10, fd);
	ft_putchar_fd((check_n * (n % 10) + '0'), fd);
}

void	ft_putnbr_fd(int	n, int	fd)
{	
	if (fd <= 0)
		return ;
	into_n(n, fd);
}
