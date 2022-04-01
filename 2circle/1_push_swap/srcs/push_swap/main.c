#include "push_swap.h"

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
	if (count == 1 || check_ascending(a, a->max_count))
		return (0);
	push_swap(a, b, count);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}
