#include "pushswap.h"

static void	rewind_stack(t_arr_stack *a, t_arr_stack *b, t_cnt *cnt, int *check)
{
	int ra;
	int	rb;

	ra = cnt->ra;
	rb = cnt->rb;
	if (*check > 0 && ra > 0) // rb 카운팅에 대해서 해법?
	{
		while (ra-- > 0 && rb-- > 0)
			ft_rrr(a, b);
		while (ra-- >= 0)
			ft_rra_rrb(a, 1);
		while (rb-- >= 0)
			ft_rra_rrb(b, 2);
	}
	else
	{
		while (rb-- > 0)
			ft_rra_rrb(b, 2);
	}
}

static void	move_b(t_arr_stack *b, t_arr_stack *a, t_cnt *cnt, int count)
{
	int	*sort;
	int i;
	int	pivot1;
	int	pivot2;

	i = -1;

	sort = malloc(sizeof(int) * count);
	if (!sort)
		error_free(a, b);
	sort_arr(b, sort);
	pivot1 = sort[b->cur_count / 3];
	pivot2 = sort[b->cur_count / 3 * 2];
	while (++i < count)
	{
		if (b->element[b->front].data < pivot1)
		{
			ft_ra_rb(b, cnt, 2);
		}
		else
		{
			ft_pa_pb(b, a, cnt, 2);
			if (a->element[a->front].data < pivot2)
				ft_ra_rb(a, cnt, 1);
		}
	}
}

static void	move_a(t_arr_stack *a, t_arr_stack *b, t_cnt *cnt, int count)
{
	int	*sort;
	int i;
	int	pivot1;
	int pivot2;

	i = -1;
	sort = malloc(sizeof(int) * count);
	if (!sort)
		error_free(a, b);
	sort_arr(a, sort);
	pivot1 = sort[a->cur_count / 3 * 2];
	pivot2 = sort[a->cur_count / 3];
	while (++i < count)
	{
		if (a->element[a->front].data >= pivot1)
			ft_ra_rb(a, cnt, 1);
		else
		{
			ft_pa_pb(a, b, cnt, 1);
			if (b->element[b->front].data >= pivot2)
				ft_ra_rb(b, cnt, 2);
		}
	}
}

void	a_to_b(t_arr_stack *a, t_arr_stack *b, int count, int *check)
{
	t_cnt cnt;

	if (count < 4)
	{
		small_arg(a, b, count, 1);
		return ;
	}
	cnt.ra = 0;
	cnt.rb= 0;
	cnt.pb = 0;
	move_a(a, b, &cnt, count);
	rewind_stack(a, b, &cnt, check);
	a_to_b(a, b, cnt.ra, check);
	b_to_a(a, b, cnt.rb, check);
	b_to_a(a, b, cnt.pb - cnt.rb, check);
}

void	b_to_a(t_arr_stack *a, t_arr_stack *b, int count, int *check)
{
	t_cnt cnt;

	*check = 1;
	if (count < 3)
	{
		small_arg(b, a, count, 2);
		return ;
	}
	cnt.ra = 0;
	cnt.rb= 0;
	cnt.pa = 0;
	move_b(b, a, &cnt, count);
	a_to_b(a, b, cnt.pa - cnt.ra, check);
	rewind_stack(a, b, &cnt, check);
	a_to_b(a, b, cnt.ra, check);
	b_to_a(a, b, cnt.rb, check);
}

void	push_swap(t_arr_stack *a, t_arr_stack *b)
{
	int sort[a->max_count];
	int	check;

	check = 0;
	sort_arr(a, sort);
	a_to_b(a, b, a->cur_count, &check);
}