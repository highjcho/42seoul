#ifndef _PUSH_SWAP_
# define _PUSH_SWAP_

// 42헤더 꼭 넣어라!!!!!!!!

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // 제출 전 삭제 필

typedef struct arr_node_type
{
	int data;
}	arr_node;

typedef struct arr_stack_type
{
	int			max_count; // 인자 개수
	int			cur_count; // 스택에 차 있는 개수
	int 		front; // 프론트
	int 		rear; // 리어
    arr_node	*element;

} arr_stack;

void	fill_stack(arr_stack *stack, char **argv);
void	insert_front(arr_stack *stack, int data);
int		remove_front(arr_stack *stack);
void	ft_sa_sb(arr_stack *stack, int flag);
void	ft_ss(arr_stack *a, arr_stack *b);
void	ft_pa_pb(arr_stack *a, arr_stack *b, int flag);
void	ft_ra_rb(arr_stack *stack, int flag);
void	ft_rr(arr_stack *a, arr_stack *b);
void	ft_rra_rrb(arr_stack *stack, int flag);
void	ft_rrr(arr_stack *a, arr_stack *b);
void 	error_handler(char *message, int error_code);

#endif