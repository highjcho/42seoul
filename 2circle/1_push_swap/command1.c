/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:57:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:00 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *stack, int flag)
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
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a, -1);
	sa_sb(b, -1);
	write(1, "ss\n", 3);
}

static void	insert_front(t_stack *stack, int	data)
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

void	pa_pb(t_stack *from, t_stack *to, t_cmd *cmd, int flag)
{
	if (from->cur_count == 0)
		return ;
	insert_front(to, remove_front(from));
	if (flag == 1)
	{
		write(1, "pb\n", 3);
		if (cmd)
			cmd->pb++;
	}
	else
	{
		write(1, "pa\n", 3);
		if (cmd)
			cmd->pa++;
	}
}
