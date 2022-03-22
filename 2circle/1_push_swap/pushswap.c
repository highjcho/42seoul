#include "pushswap.h"

static int get_count(char **argv) // static 띄어쓰기 놈?
{
	int i;
	int	j;
	int count;

	i = 0;
	count = 0;
    while (argv[i])
    {
		j = 0;
		while (argv[i][j])
		{
        	if (argv[i][j] >= '0' && argv[i][j] <= '9' && (argv[i][j + 1] == ' ' || argv[i][j + 1] == 0))
				count++;
			j++;
		}
		i++;
    }
	return (count);
}

static arr_stack	*make_stack(arr_stack *new, int count)
{
	new = malloc(sizeof(arr_stack));
	if (!new)
		error_handler("Error\n", 1);
	new->max_count = count;
	new->cur_count = 0;
	new->front = 0;
	new->rear = -1;
	new->element = malloc(count * sizeof(arr_node));
	if (!(new->element))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static void	print_arr(arr_stack *a, int flag)
{
	int pos;

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


int	main(int argc, char **argv) // 인자 중복검사 필요
{
	arr_stack *a;
	arr_stack	*b;
	int count;
	int loop = 1;
	int	opt;
    
	if (argc == 1)
		error_handler("Error\n", 1);
	else if (argc >= 2)
		count = get_count(argv);
	a = make_stack(a, count);
	if (!a)
		error_handler("Error\n", 1);
	b = make_stack(b, count);
	if (!b) // 줄일 수 있는 방법 없나
	{
		free(a->element);
		free(a);
		exit(1);
	}
	fill_stack(a, ++argv);
	if (check_ascending(a))
		return (0);
	push_swap(a, b);
}