/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:26:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/01 15:13:17 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	len;

	if (fd <= 0 || !s)
		return ;
	i = 0;
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}
