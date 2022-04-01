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

#include "checker.h"

char	*ft_calloc(int	count)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * count);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < count)
		s[i] = 0;
	return (s);
}

static void	read_cmd(t_stack *a, t_stack *b)
{
	char	*cmd;
	int		flag;

	flag = 1;
	cmd = get_next_cmd(&flag);
	if (flag < 0)
		error_free(a, b);
	while (cmd)
	{
		do_push_swap(a, b, cmd);
		free(cmd);
		cmd = get_next_cmd(&flag);
		if (flag < 0)
			error_free(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		count;

	count = 0;
	if (ac == 1)
		error_handler("Error\n", 1);
	else if (ac >= 2)
		count = get_count(av);
	a = make_stack(count);
	if (!a)
		error_handler("Error\n", 1);
	b = make_stack(count);
	if (!b)
		error_free(a, 0);
	fill_stack(a, b, ++av);
	read_cmd(a, b);
	if (check_ascending(a, a->max_count) && b->cur_count == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}