#include "pushswap.h"

void	error_free(t_arr_stack *stack1, t_arr_stack *stack2)
{
	free(stack1->element);
	free(stack1);
	if (stack2)
	{
		free(stack2->element);
		free(stack2);
	}
	error_handler("Error\n", 1);
}

void	error_handler(char *message, int error_code)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	write(1, message, i);
	exit(error_code);
}