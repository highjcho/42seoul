/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:07 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:59:08 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cmd(t_cmd *cmd)
{
	cmd->pa = 0;
	cmd->pb = 0;
	cmd->ra = 0;
	cmd->rb = 0;
}

int	check_ascending(t_stack *a, int count)
{
	int	max;
	int	i;
	int	j;

	max = a->arr[a->front].data;
	i = 0;
	j = (a->front + 1) % a->max_count;
	while (++i < count)
	{
		if (a->arr[j].data < max)
			return (0);
		max = a->arr[j].data;
		j = (j + 1) % a->max_count;
	}
	return (1);
}

int	check_descending(t_stack *b, t_stack *a, int count)
{
	int	min;
	int	i;
	int	j;

	min = b->arr[b->front].data;
	i = 0;
	j = (b->front + 1) % b->max_count;
	while (++i < count)
	{
		if (b->arr[j].data > min)
			return (0);
		min = b->arr[j].data;
		j = (j + 1) % b->max_count;
	}
	while (count-- > 0)
		pa_pb(b, a, 0, 2);
	return (1);
}

void	error_free(t_stack *stack1, t_stack *stack2)
{
	free(stack1->arr);
	free(stack1);
	if (stack2)
	{
		free(stack2->arr);
		free(stack2);
	}
	error_handler("Error\n", 1);
}

void	error_handler(char *message, int error_code)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	write(1, message, i);
	exit(error_code);
}
