/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:11:47 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:11:49 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

int	dup_fd(int from_fd, int to_fd)
{
	int	dup_ret;

	dup_ret = dup2(from_fd, to_fd);
	if (from_fd != STDIN_FILENO && from_fd != STDOUT_FILENO)
		close(from_fd);
	if (dup_ret < 0)
		return (FALSE);
	return (TRUE);
}
