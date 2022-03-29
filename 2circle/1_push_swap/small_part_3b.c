/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_part_3b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_pa(t_stack *b, t_stack *a, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pa_pb(b, a, 0, 2);
}

static void	do_pa_rr(t_stack *b, t_stack *a)
{
	do_pa(b, a, 2);
	rra_rrb(b, 2);
	pa_pb(b, a, 0, 2);
}

static void	b_other_3(t_stack *b, t_stack *a, int mid, int bottom)
{
	int	top;

	top = b->arr[b->front].data;
	if (top < mid && top < bottom && mid < bottom)
	{
		ra_rb(b, 0, 2);
		sa_sb(b, 2);
		do_pa_rr(b, a);
	}
	else if (top < mid && top < bottom && mid > bottom)
	{
		ra_rb(b, 0, 2);
		do_pa_rr(b, a);
	}
	else if (top < mid && top > bottom && mid > bottom)
	{
		sa_sb(b, 2);
		do_pa(b, a, 3);
	}
	else if (top > mid && top > bottom && mid < bottom)
	{
		pa_pb(b, a, 0, 2);
		sa_sb(b, 2);
		do_pa(b, a, 2);
	}
}

void	b_part_3(t_stack *b, t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = b->arr[b->front].data;
	mid = b->arr[(b->front + 1) % b->max_count].data;
	bottom = b->arr[(b->front + 2) % b->max_count].data;
	if (top > mid && top > bottom && mid > bottom)
		do_pa(b, a, 3);
	else if (top > mid && top < bottom && mid < bottom)
	{
		ra_rb(b, 0, 2);
		ra_rb(b, 0, 2);
		pa_pb(b, a, 0, 2);
		rra_rrb(b, 2);
		rra_rrb(b, 2);
		do_pa(b, a, 2);
	}
	else
		b_other_3(b, a, mid, bottom);
}
