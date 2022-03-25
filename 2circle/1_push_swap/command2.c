#include "pushswap.h"

void	ft_ra_rb(t_arr_stack *stack, t_cnt *cnt, int flag)
{
	int	tmp;

	tmp = stack->element[stack->front].data;
	stack->front = (stack->front + 1) % stack->max_count;
	stack->rear = (stack->rear + 1) % stack->max_count;
	stack->element[stack->rear].data = tmp;
	if (flag == 1)
	{
		write(1, "ra\n", 3);
		cnt->ra++;
	}
	else if (flag == 2)
	{
		write(1, "rb\n", 3);
		cnt->rb++;
	}
}

void	ft_rr(t_arr_stack *a, t_arr_stack *b, t_cnt *cnt)
{
	ft_ra_rb(a, cnt, -1);
	ft_ra_rb(b, cnt, -1);
	write(1, "rr\n", 3);
}

void	ft_rra_rrb(t_arr_stack *stack, int flag)
{
	int	tmp;

	tmp = stack->element[stack->rear].data;
	if (stack->front == 0)
		stack->front = stack->max_count - 1;
	else
		stack->front--;
	if (stack->rear == 0)
		stack->rear = stack->max_count - 1;
	else
		stack->rear--;
	stack->element[stack->front].data = tmp;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_arr_stack *a, t_arr_stack *b)
{
	ft_rra_rrb(a, -1);
	ft_rra_rrb(b, -1);
	write(1, "rrr\n", 4);
}