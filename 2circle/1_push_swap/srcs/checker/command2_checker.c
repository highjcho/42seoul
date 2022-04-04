/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:51:06 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 13:51:09 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_rb_checker(t_stack *stack)
{
	int	tmp;

	tmp = stack->arr[stack->front].data;
	stack->front = (stack->front + 1) % stack->max_count;
	stack->rear = (stack->rear + 1) % stack->max_count;
	stack->arr[stack->rear].data = tmp;
}

void	rr_checker(t_stack *a, t_stack *b)
{
	ra_rb_checker(a);
	ra_rb_checker(b);
}

void	rra_rrb_checker(t_stack *stack)
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
}

void	rrr_checker(t_stack *a, t_stack *b)
{
	rra_rrb_checker(a);
	rra_rrb_checker(b);
}
