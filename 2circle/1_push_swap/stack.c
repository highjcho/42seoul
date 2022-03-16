#include "pushswap.h"

void	insert_front(arr_stack *stack, int	data)
{
	if (stack->front == 0)
		stack->front = stack->max_count - 1;
	else
		stack->front--;
	stack->element[stack->front].data = data;
	stack->cur_count++;
}

int	remove_front(arr_stack *stack)
{
	int	ret;

	ret = stack->element[stack->front].data;
	stack->front = (stack->front + 1) % stack->max_count;
	stack->cur_count--;
	return (ret);
}