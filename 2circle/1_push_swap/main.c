#include "pushswap.h"

static int	get_count(char **av) // static 띄어쓰기 놈?
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
			if (av[i][j] >= '0' && av[i][j] <= '9' && (av[i][j + 1] == ' ' || av[i][j + 1] == 0)) // 줄여야 함
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static t_arr_stack	*make_stack(t_arr_stack *new, int count)
{
	new = malloc(sizeof(t_arr_stack));
	if (!new)
		error_handler("Error\n", 1);
	new->max_count = count;
	new->cur_count = 0;
	new->front = 0;
	new->rear = count - 1;
	new->element = malloc(count * sizeof(t_arr_node));
	if (!(new->element))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void	print_arr(t_arr_stack *a, int flag) // 제출전 지울 함수
{
	int	pos;

	if (flag == 1)
		printf("a: ");
	else
		printf("b: ");
	pos = a->front;
	for (int i = 0; i < a->cur_count; i++)
	{
		printf("[%d] %d ", i, a->element[pos].data);
		pos = (pos + 1) % a->max_count;
	}
	printf("\n\n");
}

static int	check_ascending(t_arr_stack *a)
{
	int	max;
	int	i;
	int j;

	max = a->element[a->front].data;
	i = -1;
	j = a->front;
	while (++i < a->max_count)
	{
		if (a->element[j].data < max)
			return (0);
		max = a->element[j].data;
		j = (j + 1) % a->max_count;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_arr_stack	*a;
	t_arr_stack	*b;
	int			count;

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
	if (count == 1 || check_ascending(a))
		return (0);
	push_swap(a, b, count);
	if (check_ascending(a))
		printf("finish!!!!\n");
}