/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:43:50 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 08:45:17 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (ac < 2)
		return (0);
	count = get_count(av);
	a = make_stack(count);
	if (!a)
		error_handler("Error\n", 1);
	b = make_stack(count);
	if (!b)
		error_free(a, 0);
	fill_stack(a, b, ++av);
	if (count == 1 || check_ascending(a, a->max_count))
		return (0);
	push_swap(a, b, count);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}
