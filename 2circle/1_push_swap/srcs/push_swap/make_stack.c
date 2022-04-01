/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:24 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:35 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(char **av)
{
	int	count;
	int	tmp;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while (av[i])
	{
		tmp = count;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9' && \
			(av[i][j + 1] == ' ' || av[i][j + 1] == 0))
				count++;
			j++;
		}
		if (count == tmp)
			error_handler("Error\n", 1);
		i++;
	}
	return (count);
}

t_stack	*make_stack(int count)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->max_count = count;
	new->cur_count = 0;
	new->front = 0;
	new->rear = count - 1;
	new->arr = malloc(count * sizeof(t_node));
	if (!(new->arr))
	{
		free(new);
		return (NULL);
	}
	return (new);
}
