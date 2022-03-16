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

int	main(int argc, char **argv)
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
	if (!b)
	{
		free(a->element);
		free(a);
		exit(1);
	}
	fill_stack(a, ++argv);
	while (loop)
	{
		printf("[1] sa [2] sb [3] ss [4] pa [5] pb [6] ra [7] rb [8] rr [9] rra [10] rrb [11] rrr [12] exit ");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:
				ft_sa_sb(a, 1);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 2:
				ft_sa_sb(b, 2);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 3:
				ft_ss(a, b);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 4:
				ft_pa_pb(a, b, 1);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 5:
				ft_pa_pb(b, a, 2);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 6:
				ft_ra_rb(a, 1);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 7:
				ft_ra_rb(b, 2);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 8:
				ft_rr(a, b);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 9:
				ft_rra_rrb(a, 1);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 10:
				ft_rra_rrb(b, 2);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 11:
				ft_rrr(a, b);
				print_arr(a, 1);
				print_arr(b, 2);
				break;
			case 12:
				loop = 0;
				break;
		}
	}
}