/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:10:18 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:10:20 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	mini_pwd(void)
{
	char	dir[4096];
	char	*check;

	ft_bzero(dir, 4096);
	check = getcwd(dir, 4096);
	if (check == NULL)
		return (FAIL);
	printf("%s\n", dir);
	return (SUCCESS);
}
