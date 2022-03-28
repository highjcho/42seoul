#include "pushswap.h"


static void	arg_2(t_arr_stack *from, t_arr_stack *to, t_cnt *cnt, int flag)
{
	int first;
	int second;
	int	i;

	first = from->front;
	second = (first + 1) % from->max_count;
	if (flag == 1)
	{
		if (from->element[first].data > from->element[second].data)
			ft_sa_sb(from, flag);
	}
	else
	{
		if (from->element[second].data > from->element[first].data)
			ft_sa_sb(from, flag);
		i = -1;
		while (++i < 2)
			ft_pa_pb(from, to, cnt, flag);
	}
}

static void	arg_3_a(t_arr_stack *s, t_cnt *cnt, int flag)
{
	int top;
	int mid;
	int bottom;

	top = s->element[s->front].data;
	mid = s->element[(s->front + 1) % s->max_count].data;
	bottom = s->element[(s->front + 2) % s->max_count].data;
	if (mid < top && mid < bottom && top < bottom)
		ft_sa_sb(s, 1);
	else if (mid < top && mid < bottom && top > bottom)
	{
		ft_sa_sb(s, 1);
		ft_ra_rb(s, cnt, 1);
		ft_sa_sb(s, 1);
		ft_rra_rrb(s, 1);
	}
	else if (mid > top && mid > bottom && top > bottom)
	{
		ft_ra_rb(s, cnt, 1);
		ft_sa_sb(s, 1);
		ft_rra_rrb(s, 1);
		ft_sa_sb(s, 1);
	}
	else if (mid > top && mid > bottom && top < bottom)
	{
		ft_ra_rb(s, cnt, 1);
		ft_sa_sb(s, 1);
		ft_rra_rrb(s, 1);
	}
	else if (mid < top && mid > bottom && top > bottom)
	{
		ft_sa_sb(s, 1);
		ft_ra_rb(s, cnt, 1);
		ft_sa_sb(s, 1);
		ft_rra_rrb(s, 1);
		ft_sa_sb(s, 1);
	}
}

static void	arg_3_b(t_arr_stack *b, t_arr_stack *a, t_cnt *cnt, int flag)
{
	int top;
	int mid;
	int bottom;
	int	i;

	top = b->element[b->front].data;
	mid = b->element[(b->front + 1) % b->max_count].data;
	bottom = b->element[(b->front + 2) % b->max_count].data;
	if (mid < top && mid < bottom && top < bottom)
	{
		ft_ra_rb(b, cnt, 2);
		ft_ra_rb(b, cnt, 2);
		ft_pa_pb(b, a, cnt, 2);
		ft_rra_rrb(b, 2);
		ft_rra_rrb(b, 2);
		ft_pa_pb(b, a, cnt, 2);
		ft_pa_pb(b, a, cnt, 2);
	}
	else if (mid < top && mid < bottom && top > bottom)
	{
		ft_pa_pb(b, a, cnt, 2);
		ft_sa_sb(b, 2);
		ft_pa_pb(b, a, cnt, 2);
		ft_pa_pb(b, a, cnt, 2);
	}
	else if (mid > top && mid > bottom && top > bottom)
	{
		ft_sa_sb(b, 2);
		i = -1;
		while (++i < 3)
			ft_pa_pb(b, a, cnt, 2);
	}
	else if (mid > top && mid < bottom && top < bottom)
	{
		ft_ra_rb(b, cnt, 2);
		ft_sa_sb(b, 2);
		ft_pa_pb(b, a, cnt, 2);
		ft_pa_pb(b, a, cnt, 2);
		ft_rra_rrb(b, 2);
		ft_pa_pb(b, a, cnt, 2);
	}
	else if (mid > top && mid > bottom && top < bottom)
	{
		ft_ra_rb(b, cnt, 1);
		i = -1;
		while (++i < 2)
			ft_pa_pb(b, a, cnt, 2);
		ft_rra_rrb(b, 2);
		ft_pa_pb(b, a, cnt, 2);
	}
	else if (mid < top && mid > bottom && top > bottom)
	{
		i = -1;
		while (++i < 3)
			ft_pa_pb(b, a, cnt, 2);
	}
}

// static void 

void	small_arg(t_arr_stack *from, t_arr_stack *to, int count, int flag)
{
	t_cnt cnt;

	cnt.ra = 0; // set 함수 만들기
	if (count == 1 && flag == 1)
		return ;
	else if (count == 1 && flag == 2)
		ft_pa_pb(from, to, &cnt, flag);
	else if (count == 2)
		arg_2(from, to, &cnt, flag);
	else if (count == 3 && flag == 1)
		arg_3_a(from, &cnt, flag);
	else if (count == 3 && flag == 2)
	 	arg_3_b(from, to, &cnt, flag);
	// else if (count == 4 && flag == 1)
	// 	arg_4_a(from, to, &cnt, flag);

}