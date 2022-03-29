/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_part_3a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:52 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:53 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	ra_rb(a, 0, 1);
	sa_sb(a, 1);
	rra_rrb(a, 1);
}

static void	a_other_3(t_stack *a, int top, int mid, int bottom)
{
	if (top < mid && top < bottom && mid > bottom)
		sort_three(a);
	else if (top < mid && top > bottom && mid > bottom)
	{
		sort_three(a);
		sa_sb(a, 1);
	}
	else if (top > mid && top > bottom && mid < bottom)
	{
		sa_sb(a, 1);
		sort_three(a);
	}
	else if (top > mid && top > bottom && mid > bottom)
	{
		sa_sb(a, 1);
		sort_three(a);
		sa_sb(a, 1);
	}
}

void	a_part_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	if (a->cur_count == 3)
		sort_three(a);
	top = a->arr[a->front].data;
	mid = a->arr[(a->front + 1) % a->max_count].data;
	bottom = a->arr[(a->front + 2) % a->max_count].data;
	if (top > mid && top < bottom && mid < bottom)
		sa_sb(a, 1);
	else
		a_other_3(a, top, mid, bottom);
}
