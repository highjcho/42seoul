/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:03 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:07 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack *stack, t_cmd *cmd, int flag)
{
	int	tmp;

	tmp = stack->arr[stack->front].data;
	stack->front = (stack->front + 1) % stack->max_count;
	stack->rear = (stack->rear + 1) % stack->max_count;
	stack->arr[stack->rear].data = tmp;
	if (flag == 1)
	{
		write(1, "ra\n", 3);
		if (cmd)
			cmd->ra++;
	}
	else if (flag == 2)
	{
		write(1, "rb\n", 3);
		if (cmd)
			cmd->rb++;
	}
}

void	rr(t_stack *a, t_stack *b, t_cmd *cmd)
{
	ra_rb(a, cmd, -1);
	ra_rb(b, cmd, -1);
	write(1, "rr\n", 3);
}

void	rra_rrb(t_stack *stack, int flag)
{
	int	tmp;

	tmp = stack->arr[stack->rear].data;
	if (stack->front == 0)
		stack->front = stack->max_count - 1;
	else
		stack->front--;
	if (stack->rear == 0)
		stack->rear = stack->max_count - 1;
	else
		stack->rear--;
	stack->arr[stack->front].data = tmp;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra_rrb(a, -1);
	rra_rrb(b, -1);
	write(1, "rrr\n", 4);
}
