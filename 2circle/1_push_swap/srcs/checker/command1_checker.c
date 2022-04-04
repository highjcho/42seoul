/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:50:53 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 13:50:56 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_sb_checker(t_stack *stack)
{
	int	first;
	int	second;
	int	tmp;

	if (stack->cur_count < 2)
		return ;
	first = stack->front;
	second = (first + 1) % stack->max_count;
	tmp = stack->arr[first].data;
	stack->arr[first].data = stack->arr[second].data;
	stack->arr[second].data = tmp;
}

void	ss_checker(t_stack *a, t_stack *b)
{
	sa_sb_checker(a);
	sa_sb_checker(b);
}

static void	insert_front(t_stack *stack, int data)
{
	if (stack->front == 0)
		stack->front = stack->max_count - 1;
	else
		stack->front--;
	stack->arr[stack->front].data = data;
	stack->cur_count++;
}

static int	remove_front(t_stack *stack)
{
	int	ret;

	ret = stack->arr[stack->front].data;
	stack->front = (stack->front + 1) % stack->max_count;
	stack->cur_count--;
	return (ret);
}

void	pa_pb_checker(t_stack *from, t_stack *to)
{
	if (from->cur_count == 0)
		return ;
	insert_front(to, remove_front(from));
}
