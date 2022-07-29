/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setattr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:40:51 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 12:41:08 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	setechoctl(int flag)
{
	struct termios	new_term;

	tcgetattr(STDIN_FILENO, &new_term);
	if (flag)
		new_term.c_lflag &= ~(ECHOCTL);
	else
		new_term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
}
