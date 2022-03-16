#include "pushswap.h"

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
	while (**argv >= '0' && **argv <= '9')
	{
		tmp = *num;
		*num = (sign * (**argv - '0')) + (*num * 10);
		if (tmp != *num / 10)
			error_handler("Error\n", 1); // errno
		(*argv)++;
	}
	return (argv);
}

void	fill_stack(arr_stack *stack, char **argv)
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
		}
		argv++;
	}
}