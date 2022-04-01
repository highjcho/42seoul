/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:40 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:45 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rewind_stack(t_stack *a, t_stack *b, t_cmd *cmd, int *check)
{
	int	ra;
	int	rb;

	ra = cmd->ra;
	rb = cmd->rb;
	if (*check > 0 && ra > 0)
	{
		while (ra-- > 0 && rb-- > 0)
			rrr(a, b);
		while (ra-- >= 0)
			rra_rrb(a, 1);
		while (rb-- > 0)
			rra_rrb(b, 2);
	}
	else
	{
		while (rb-- > 0)
			rra_rrb(b, 2);
	}
}

static void	move_a(t_stack *a, t_stack *b, t_cmd *cmd, int count)
{
	int	*sort;
	int	pivot1;
	int	pivot2;
	int	i;

	sort = sort_arr(a, b, count);
	pivot1 = sort[count / 3 * 2];
	pivot2 = sort[count / 3];
	free(sort);
	i = -1;
	while (++i < count)
	{
		if (a->arr[a->front].data >= pivot1)
			ra_rb(a, cmd, 1);
		else
		{
			pa_pb(a, b, cmd, 1);
			if (b->arr[b->front].data >= pivot2)
				ra_rb(b, cmd, 2);
		}
	}
}

void	a_to_b(t_stack *a, t_stack *b, int count, int *check)
{
	t_cmd	cmd;

	if (count < 6)
	{
		if (check_ascending(a, count))
			return ;
		small_part(a, b, count, 1);
		return ;
	}
	set_cmd(&cmd);
	move_a(a, b, &cmd, count);
	rewind_stack(a, b, &cmd, check);
	a_to_b(a, b, cmd.ra, check);
	b_to_a(a, b, cmd.rb, check);
	b_to_a(a, b, cmd.pb - cmd.rb, check);
}

static void	move_b(t_stack *b, t_stack *a, t_cmd *cmd, int count)
{
	int	*sort;
	int	pivot1;
	int	pivot2;
	int	i;

	sort = sort_arr(b, a, count);
	pivot1 = sort[count / 3];
	pivot2 = sort[count / 3 * 2];
	i = -1;
	free(sort);
	while (++i < count)
	{
		if (b->arr[b->front].data < pivot1)
			ra_rb(b, cmd, 2);
		else
		{
			pa_pb(b, a, cmd, 2);
			if (a->arr[a->front].data < pivot2)
				ra_rb(a, cmd, 1);
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b, int count, int *check)
{
	t_cmd	cmd;

	*check = 1;
	if (count < 6)
	{
		if (check_descending(b, a, count))
			return ;
		small_part(b, a, count, 2);
		return ;
	}
	set_cmd(&cmd);
	move_b(b, a, &cmd, count);
	a_to_b(a, b, cmd.pa - cmd.ra, check);
	rewind_stack(a, b, &cmd, check);
	a_to_b(a, b, cmd.ra, check);
	b_to_a(a, b, cmd.rb, check);
}
