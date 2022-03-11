#include "pushswap.h"

static void	tmp(array_stack *stack, int num)
{
	stack->element[stack->cur_count].data = num;
	stack->cur_count++;
	stack->front++;
}