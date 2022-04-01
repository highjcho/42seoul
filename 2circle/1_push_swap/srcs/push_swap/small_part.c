/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:47 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:49 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	part_2(t_stack *from, t_stack *to, t_cmd *cmd, int flag)
{
	int	first;
	int	second;
	int	i;

	first = from->front;
	second = (first + 1) % from->max_count;
	if (flag == 1)
	{
		if (from->arr[first].data > from->arr[second].data)
			sa_sb(from, flag);
	}
	else
	{
		if (from->arr[second].data > from->arr[first].data)
			sa_sb(from, flag);
		i = -1;
		while (++i < 2)
			pa_pb(from, to, cmd, flag);
	}
}

static void	a_part_5(t_stack *a, t_stack *b, int count)
{
	t_cmd	cmd;
	int		*sort;
	int		mid;

	if (a->cur_count == 5)
	{
		sort_5_a(a, b);
		return ;
	}
	set_cmd(&cmd);
	sort = sort_arr(a, b, count);
	mid = sort[2];
	while (cmd.pb < 2)
	{
		if (a->arr[a->front].data < mid)
			pa_pb(a, b, &cmd, 1);
		else
			ra_rb(a, &cmd, 1);
	}
	while (count < a->cur_count && cmd.ra-- > 0)
		rra_rrb(a, 1);
	a_part_3(a);
	part_2(b, a, 0, 2);
}

static void	sort_5_b(t_stack *b, t_stack *a)
{
	t_cmd	cmd;
	int		*sort;
	int		mid;

	sort = sort_arr(b, a, 5);
	mid = sort[1];
	set_cmd(&cmd);
	while (cmd.pa < 3)
	{
		if (b->arr[b->front].data > mid)
			pa_pb(b, a, &cmd, 2);
		else
			ra_rb(b, 0, 2);
	}
	a_part_3(a);
	part_2(b, a, 0, 2);
}

static void	b_part_5(t_stack *b, t_stack *a, int count)
{
	t_cmd	cmd;
	int		*sort;
	int		mid;

	set_cmd(&cmd);
	if (b->cur_count == 5)
	{
		sort_5_b(b, a);
		return ;
	}
	sort = sort_arr(b, a, count);
	mid = sort[1];
	while (cmd.pa < 3)
	{
		if (b->arr[b->front].data > mid)
			pa_pb(b, a, &cmd, 2);
		else
			ra_rb(b, &cmd, 2);
	}
	while (cmd.rb-- > 0)
		rra_rrb(b, 2);
	a_part_3(a);
	part_2(b, a, 0, 2);
}

void	small_part(t_stack *from, t_stack *to, int count, int flag)
{
	if (count == 1 && flag == 1)
		return ;
	else if (count == 1 && flag == 2)
		pa_pb(from, to, 0, flag);
	else if (count == 2)
		part_2(from, to, 0, flag);
	else if (count == 3 && flag == 1)
		a_part_3(from);
	else if (count == 3 && flag == 2)
		b_part_3(from, to);
	else if (count == 4 && flag == 1)
		a_part_4(from, to, count, from->arr[from->front].data);
	else if (count == 4 && flag == 2)
		b_part_4(from, to, count, from->arr[from->front].data);
	else if (count == 5 && flag == 1)
		a_part_5(from, to, count);
	else if (count == 5 && flag == 2)
		b_part_5(from, to, count);
}
