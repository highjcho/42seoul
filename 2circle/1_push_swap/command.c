#include "pushswap.h"

void	ft_sa_sb(arr_stack *stack, int flag)
{
	int	first;
	int	second;
	int	tmp;

    if (stack->cur_count < 2)
		return ;
	first = stack->front;
	second = first + 1;
	if (first == stack->max_count - 1)
		second = 0;
	tmp = stack->element[first].data;
	stack->element[first].data = stack->element[second].data;
	stack->element[second].data = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
}

void	ft_ss(arr_stack *a, arr_stack *b)
{
	ft_sa_sb(a, -1);
	ft_sa_sb(b, -1);
	write(1, "ss\n", 3);
}

void	ft_pa_pb(arr_stack *a, arr_stack *b, int flag)
{
	if (b->cur_count == 0)
		return ;
	insert_front(a, remove_front(b));
	if (flag == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	ft_ra_rb(arr_stack *stack, int flag)
{
	int	tmp;

	tmp = stack->element[stack->front].data;
	stack->front = (stack->front + 1) % stack->max_count;
	stack->rear = (stack->rear + 1) % stack->max_count;
	stack->element[stack->rear].data = tmp;
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 2)
		write(1, "rb\n", 3);
}

void	ft_rr(arr_stack *a, arr_stack *b)
{
	ft_ra_rb(a, -1);
	ft_ra_rb(b, -1);
	write(1, "rr\n", 3);
}

void	ft_rra_rrb(arr_stack *stack, int flag)
{
	int	tmp;

	tmp = stack->element[stack->rear].data;
	if (stack->front == 0)
		stack->front = stack->max_count - 1;
	else
		stack->front--;
	stack->element[stack->front].data = tmp;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
}

void	ft_rrr(arr_stack *a, arr_stack *b)
{
	ft_rra_rrb(a, -1);
	ft_rra_rrb(b, -1);
	write(1, "rrr\n", 4);
}