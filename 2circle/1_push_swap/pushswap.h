#ifndef _PUSH_SWAP_
# define _PUSH_SWAP_

// 42헤더 꼭 넣어라!!!!!!!!

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // 제출 전 삭제 필

typedef struct s_cnt_type
{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_cnt;

typedef struct s_arr_node_type
{
	int data;
}	t_arr_node;

typedef struct s_arr_stack_type
{
	int			max_count; // 인자 개수
	int			cur_count; // 스택에 차 있는 개수
	int 		front; // 프론트
	int 		rear; // 리어
    t_arr_node	*element;
}	t_arr_stack;

void	fill_stack(t_arr_stack *stack, char **argv);
void 	push_swap(t_arr_stack *a, t_arr_stack *b, int count);
void	less_five(t_arr_stack *a, t_arr_stack *b, int count);
void	b_to_a(t_arr_stack *a, t_arr_stack *b, int count, int *check);
void	a_to_b(t_arr_stack *a, t_arr_stack *b, int count, int *check);
void	small_arg(t_arr_stack *a, t_arr_stack *b, int count, int flag);
void	ft_sa_sb(t_arr_stack *stack, int flag);
void	ft_ss(t_arr_stack *a, t_arr_stack *b);
void	ft_pa_pb(t_arr_stack *from, t_arr_stack *to, t_cnt *cnt, int flag);
void	ft_ra_rb(t_arr_stack *stack, t_cnt *cnt, int flag);
void	ft_rr(t_arr_stack *a, t_arr_stack *b, t_cnt *cnt);
void	ft_rra_rrb(t_arr_stack *stack, int flag);
void	ft_rrr(t_arr_stack *a, t_arr_stack *b);
void	sort_arr(t_arr_stack *a, int *sort, int count);
void	set_cnt(t_cnt *cnt);
void 	error_handler(char *message, int error_code);
void	error_free(t_arr_stack *stack1, t_arr_stack *stack2);
void	print_arr(t_arr_stack *a, int flag); //제출전 지우기

#endif