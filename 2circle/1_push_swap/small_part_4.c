/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_part_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:00 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:59:01 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a, int count, int min)
{
	int	pos;
	int	i;
	int	j;

	pos = 0;
	i = 0;
	j = (a->front + 1) % a->max_count;
	while (++i < count)
	{
		if (a->arr[j].data < min)
		{
			min = a->arr[j].data;
			pos = i;
		}
		j = (j + 1) % a->max_count;
	}
	return (pos);
}

void	a_part_4(t_stack *a, t_stack *b, int count, int min)
{
	t_cmd	cmd;
	int		pos;

	if (a->cur_count == 4)
	{
		sort_4(a, b, a->arr[a->front].data);
		return ;
	}
	set_cmd(&cmd);
	pos = find_min(a, count, min);
	while (pos-- > 0)
		ra_rb(a, &cmd, 1);
	pa_pb(a, b, 0, 1);
	while (count < a->cur_count && cmd.ra-- > 0)
		rra_rrb(a, 1);
	a_part_3(a);
	pa_pb(b, a, 0, 2);
}

static int	find_max(t_stack *b, int count, int max)
{
	int	pos;
	int	i;
	int	j;

	pos = 0;
	i = 0;
	j = (b->front + 1) % b->max_count;
	while (++i < count)
	{
		if (b->arr[j].data > max)
		{
			max = b->arr[j].data;
			pos = i;
		}
		j = (j + 1) % b->max_count;
	}
	return (pos);
}

void	b_part_4(t_stack *b, t_stack *a, int count, int max)
{
	t_cmd	cmd;
	int		pos;

	set_cmd(&cmd);
	pos = find_max(b, count, max);
	while (pos-- > 0)
		ra_rb(b, &cmd, 2);
	pa_pb(b, a, 0, 2);
	while (cmd.rb-- > 0)
		rra_rrb(b, 2);
	b_part_3(b, a);
}
