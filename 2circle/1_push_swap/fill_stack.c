/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:14 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_atoi(char **s, int *num)
{
	int	sign;
	int	tmp;

	*num = 0;
	sign = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	while (**s >= '0' && **s <= '9')
	{
		tmp = *num;
		*num = (sign * (**s - '0')) + (*num * 10);
		if (tmp != *num / 10)
			error_handler("Error\n", 1);
		(*s)++;
	}
	if (!(**s == ' ' || **s == 0))
		return (NULL);
	return (s);
}

static void	check_dup(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->max_count - 1)
	{
		j = i + 1;
		while (j < a->max_count)
		{
			if (a->arr[i].data == a->arr[j].data)
				error_handler("Error\n", 1);
			j++;
		}
		i++;
	}
}

void	fill_stack(t_stack *a, char **s)
{
	int	num;

	while (*s)
	{
		while (**s)
		{
			if (**s == '-' || **s == '+' || (**s >= '0' && **s <= '9'))
			{
				s = ft_atoi(s, &num);
				if (!s)
					error_free(a, 0);
				a->arr[a->cur_count++].data = num;
				a->rear++;
			}
			else
				(*s)++;
		}
		s++;
	}
	check_dup(a);
}
