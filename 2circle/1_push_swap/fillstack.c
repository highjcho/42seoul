#include "pushswap.h"

static char	**ft_atoi(char **argv, int *num) // 문자나 이런거 들어오면 에러처리 확인 필ㄴ
{
	int	sign;
	int	tmp;

	*num = 0;
	sign = 1;
	if (**argv == '-' || **argv == '+')
	{
		if (**argv == '-')
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
	if (!(**argv == ' ' || **argv == 0))
		return (NULL);
	return (argv);
}

static void	check_dup(arr_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->max_count - 1)
	{
		j = i + 1;
		while (j < stack->max_count)
		{
			if (stack->element[i].data == stack->element[j].data)
				error_handler("Error\n", 1);
			j++;
		}
		i++;
	}
}

void	fill_stack(arr_stack *stack, char **argv)
{
	int	num;

	while (*argv)
	{
		while (**argv)
		{

			if (**argv == '-' || **argv == '+' || (**argv >= '0' && **argv <= '9'))
			{
				argv = ft_atoi(argv, &num);
				if (argv == NULL)
				{
					free(stack->element);
					free(stack);
					error_handler("Error\n", 1);
				}
				stack->element[stack->cur_count++].data = num;
				stack->rear++;
			}
			else
				(*argv)++;
		}
		argv++;
	}
	check_dup(stack);
}