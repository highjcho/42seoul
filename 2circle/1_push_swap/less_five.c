#include "pushswap.h"

static void	sort_three(t_arr_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->element[a->front].data;
	mid = a->element[(a->front + 1) % a->max_count].data;
	bottom = a->element[(a->front + 2) % a->max_count].data;
	if (top < mid && top < bottom && mid > bottom) // 132
	{
		ft_sa_sb(a, 1);
		ft_ra_rb(a, 0, 1);
	}
	else if (top > mid && top < bottom && mid < bottom) // 213
		ft_sa_sb(a, 1);
	else if (top < mid && top > bottom && mid > bottom) // 231
		ft_rra_rrb(a, 1);
	else if (top > mid && top > bottom && mid < bottom) // 312
		ft_ra_rb(a, 0, 1);
	else if (top > mid && top > bottom && mid > bottom) // 321
	{
		ft_sa_sb(a, 1);
		ft_rra_rrb(a, 1);
	}
	// exit(1);
}

static void	sort_four(t_arr_stack *a, t_arr_stack *b) // 더 효율적인 방법 없나
{
	int pos;
	int min;
	int i;

	pos = 0;
	min = a->element[0].data;
	i = 0;
	while (++i < 4)
	{
		if (a->element[i].data < min)
		{
			min = a->element[i].data;
			pos = i;
		}
	}
	if (pos == 1)
		ft_ra_rb(a, 0, 1);
	else if (pos == 2)
	{
		ft_ra_rb(a, 0, 1);
		ft_ra_rb(a, 0, 1);
	}
	else if (pos == 3)
		ft_rra_rrb(a, 1);
	ft_pa_pb(a, b, 0, 1);
	sort_three(a);
	ft_pa_pb(b, a, 0, 2); // 이 3줄을 따로 빼..ㅎ.. ㅠ
}

static void	sort_five(t_arr_stack *a, t_arr_stack *b)
{
	int *sort;
	int	mid;
	t_cnt cnt;

	sort = malloc(sizeof(int) * 5);
	sort_arr(a, sort, 5); // 이 함수가 sort 포인터를 반환하게 하고 말록 처리도 거기서 해버리자
	mid = sort[1];
	set_cnt(&cnt);
	while(cnt.pb < 2)
	{
		if (a->element[a->front].data > mid)
			ft_ra_rb(a, 0, 1);
		else
			ft_pa_pb(a, b, &cnt, 1);
	}
	sort_three(a);
	if (b->element[b->front].data < b->element[(b->front + 1) % b->max_count].data) //element도 이름 바꾸자 걍;
		ft_sa_sb(b, 2);
	while(cnt.pb-- > 0)
		ft_pa_pb(b, a, &cnt, 0);
}

void	less_five(t_arr_stack *a, t_arr_stack *b, int count)
{
	if (count == 2)
		ft_sa_sb(a, 1);
	else if (count == 3)
		sort_three(a);
	else if (count == 4)
		sort_four(a, b);
	else if (count == 5)
		sort_five(a, b);
}