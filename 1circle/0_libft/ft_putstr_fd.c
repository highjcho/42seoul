/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:18:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/01 16:56:47 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char	*s, int	fd)
{
	int	i;

	if (fd <= 0 || !s)
		return ;
	i = 0;
	while (*s)
		write(fd, s++, 1);
}
