#include "pushswap.h"

void	ft_sa_sb(t_arr_stack *stack, int flag)
{
	int	first;
	int	second;
	int	tmp;

    if (stack->cur_count < 2)
		return ;
	first = stack->front;
	second = (first + 1) % stack->max_count;
	tmp = stack->element[first].data;
	stack->element[first].data = stack->element[second].data;
	stack->element[second].data = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
}

void	ft_ss(t_arr_stack *a, t_arr_stack *b)
{
	ft_sa_sb(a, -1);
	ft_sa_sb(b, -1);
	write(1, "ss\n", 3);
}

static void	insert_front(t_arr_stack *stack, int	data)
{
	if (stack->front == 0)
		stack->front = stack->max_count - 1;
	else
		stack->front--;
	stack->element[stack->front].data = data;
	stack->cur_count++;
}

static int	remove_front(t_arr_stack *stack)
{
	int	ret;

	ret = stack->element[stack->front].data;
	stack->front = (stack->front + 1) % stack->max_count;
	stack->cur_count--;
	return (ret);
}

void	ft_pa_pb(t_arr_stack *from, t_arr_stack *to, t_cnt *cnt, int flag)
{
	if (from->cur_count == 0)
		return ;
	insert_front(to, remove_front(from));
	if (flag == 1)
	{
		write(1, "pb\n", 3);
		if (cnt)
			cnt->pb++;
	}
	else
	{
		write(1, "pa\n", 3);
		if (cnt)
			cnt->pa++;
	}
}