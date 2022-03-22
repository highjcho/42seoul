#include "pushswap.h"

static char	**ft_atoi(char **argv, int *num) // 문자나 이런거 들어오면 에러처리 확인 필ㄴ
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
	while (**argv)
	{
		if (**argv >= '0' && **argv <= '9')
		{
			tmp = *num;
			*num = (sign * (**argv - '0')) + (*num * 10);
			if (tmp != *num / 10)
				error_handler("Error\n", 1); // errno
		}
		else if (**argv != ' ') // 띄어쓰기와, 숫자를 제외한 모든 문자가 등장 시 에러
			error_handler("Error\n", 1);
		(*argv)++;
	}
	return (argv);
}

static int	check_dup(arr_stack *stack)

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
	if (check_dup(stack))
		error_handler("Error\n", 1);
}