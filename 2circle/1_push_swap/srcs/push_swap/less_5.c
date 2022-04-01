/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:19 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:21 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->arr[a->front].data;
	mid = a->arr[(a->front + 1) % a->max_count].data;
	bottom = a->arr[(a->front + 2) % a->max_count].data;
	if (top < mid && top < bottom && mid > bottom)
	{
		sa_sb(a, 1);
		ra_rb(a, 0, 1);
	}
	else if (top > mid && top < bottom && mid < bottom)
		sa_sb(a, 1);
	else if (top < mid && top > bottom && mid > bottom)
		rra_rrb(a, 1);
	else if (top > mid && top > bottom && mid < bottom)
		ra_rb(a, 0, 1);
	else if (top > mid && top > bottom && mid > bottom)
	{
		sa_sb(a, 1);
		rra_rrb(a, 1);
	}
}

static void	push_3(t_stack *a, t_stack *b)
{
	pa_pb(a, b, 0, 1);
	sort_3(a);
	pa_pb(b, a, 0, 2);
}

void	sort_4(t_stack *a, t_stack *b, int min)
{
	int	pos;
	int	i;
	int	j;

	pos = 0;
	i = 0;
	j = (a->front + 1) % a->max_count;
	while (++i < 4)
	{
		if (a->arr[j].data < min)
		{
			min = a->arr[j].data;
			pos = i;
		}
		j = (j + 1) % a->max_count;
	}
	while (pos <= 2 && pos != 0)
	{
		ra_rb(a, 0, 1);
		pos--;
	}
	if (pos == 3)
		rra_rrb(a, 1);
	push_3(a, b);
}

void	sort_5_a(t_stack *a, t_stack *b)
{
	t_cmd	cmd;
	int		*sort;
	int		mid;

	sort = sort_arr(a, b, 5);
	mid = sort[1];
	set_cmd(&cmd);
	while (cmd.pb < 2)
	{
		if (a->arr[a->front].data > mid)
			ra_rb(a, &cmd, 1);
		else
			pa_pb(a, b, &cmd, 1);
	}
	sort_3(a);
	if (b->arr[b->front].data < b->arr[(b->front + 1) % b->max_count].data)
		sa_sb(b, 2);
	while (cmd.pb-- > 0)
		pa_pb(b, a, &cmd, 0);
}

void	less_5(t_stack *a, t_stack *b, int count)
{
	if (count == 2)
		sa_sb(a, 1);
	else if (count == 3)
		sort_3(a);
	else if (count == 4)
		sort_4(a, b, a->arr[a->front].data);
	else if (count == 5)
		sort_5_a(a, b);
}