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

static int	get_count(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9' && \
			(av[i][j + 1] == ' ' || av[i][j + 1] == 0))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static t_stack	*make_stack(t_stack *new, int count)
{
	new = malloc(sizeof(t_stack));
	if (!new)
		error_handler("Error\n", 1);
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

static void	less_5(t_stack *a, t_stack *b, int count)
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

static void	push_swap(t_stack *a, t_stack *b, int count)
{
	int	check;

	check = 0;
	if (count < 6)
	{
		less_5(a, b, count);
		return ;
	}
	a_to_b(a, b, count, &check);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		count;

	count = 0;
	a = NULL;
	b = NULL;
	if (ac == 1)
		error_handler("Error\n", 1);
	else if (ac >= 2)
		count = get_count(av);
	a = make_stack(a, count);
	if (!a)
		error_handler("Error\n", 1);
	b = make_stack(b, count);
	if (!b)
		error_free(a, 0);
	fill_stack(a, ++av);
	if (count == 1 || check_ascending(a, a->max_count))
		return (0);
	push_swap(a, b, count);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
}
