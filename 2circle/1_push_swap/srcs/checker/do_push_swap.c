/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:40:52 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 08:42:14 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(char *s1, char *s2, int count)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && i < count)
		i++;
	return (s1[i] - s2[i]);
}

void	do_push_swap(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", ft_strlen(cmd)))
		sa_sb_checker(a);
	else if (!ft_strncmp(cmd, "sb\n", ft_strlen(cmd)))
		sa_sb_checker(b);
	else if (!ft_strncmp(cmd, "ss\n", ft_strlen(cmd)))
		ss_checker(a, b);
	else if (!ft_strncmp(cmd, "pa\n", ft_strlen(cmd)))
		pa_pb_checker(b, a);
	else if (!ft_strncmp(cmd, "pb\n", ft_strlen(cmd)))
		pa_pb_checker(a, b);
	else if (!ft_strncmp(cmd, "ra\n", ft_strlen(cmd)))
		ra_rb_checker(a);
	else if (!ft_strncmp(cmd, "rb\n", ft_strlen(cmd)))
		ra_rb_checker(b);
	else if (!ft_strncmp(cmd, "rr\n", ft_strlen(cmd)))
		rr_checker(a, b);
	else if (!ft_strncmp(cmd, "rra\n", ft_strlen(cmd)))
		rra_rrb_checker(a);
	else if (!ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)))
		rra_rrb_checker(b);
	else if (!ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)))
		rrr_checker(a, b);
	else
		error_free(a, b);
}
