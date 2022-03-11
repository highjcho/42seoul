#include "pushswap.h"

void error_handler(char *message, int error_code)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	write(1, message, i);
	exit(error_code);
}

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

static array_stack	*make_stack(array_stack *new, int count)
{
	new = malloc(sizeof(array_stack));
	if (!new)
		error_handler("Allocate failed\n", 1);
	new->max_count = count;
	new->cur_count = 0;
	new->front = 0;
	new->rear = -1;
	new->element = malloc(count * sizeof(array_node));
	if (!(new->element))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static char	**ft_atoi(char **argv, int *num)
{
	int	sign;
	int	tmp;

	*num = 0;
	sign = 1;
	if (**argv == '-')
	{
		sign = -1;
		(*argv)++;
	}
	printf("c: %c\n", **argv);
	while (**argv >= '0' && **argv <= '9')
	{
		tmp = *num;
		*num = (sign * (**argv - '0')) + (*num * 10);
		if (tmp != *num / 10)
			error_handler("Error\n", 1); // errno
		(*argv)++;
	}
	printf("atoi num: %d\n", *num);
	return (argv);
}

static void	fill_stack(array_stack *stack, char **argv)
{
	int	num;

	while (*argv)
	{
		while (**argv)
		{
			if (**argv == '-' || (**argv >= '0' && **argv <= '9'))
			{
				argv = ft_atoi(argv, &num);
				stack->element[stack->cur_count++].data = num;
			}
			else
				(*argv)++;
			printf("num:%d\n", num);
		}
		argv++;
	}
}

int	main(int argc, char **argv)
{
	array_stack *a;
	array_stack	*b;
	int count;
    
	if (argc == 1)
		error_handler("Error\n", 1);
	else if (argc >= 2)
		count = get_count (argv);
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
}