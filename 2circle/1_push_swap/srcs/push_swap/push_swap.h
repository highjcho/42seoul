/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:44:00 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 08:44:02 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int	data;
}	t_node;

typedef struct s_stack
{
	int		max_count;
	int		cur_count;
	int		front;
	int		rear;
	t_node	*arr;
}	t_stack;

typedef struct s_cmd
{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_cmd;

t_stack	*make_stack(int count);
void	fill_stack(t_stack *a, t_stack *b, char **s);
int		get_count(char **av);
void	less_5(t_stack *a, t_stack *b, int count);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b, int min);
void	sort_5_a(t_stack *a, t_stack *b);
void	b_to_a(t_stack *a, t_stack *b, int count, int *check);
void	a_to_b(t_stack *a, t_stack *b, int count, int *check);
void	small_part(t_stack *a, t_stack *b, int count, int flag);
void	a_part_3(t_stack *a);
void	b_part_3(t_stack *b, t_stack *a);
void	a_part_4(t_stack *a, t_stack *b, int count, int min);
void	b_part_4(t_stack *b, t_stack *a, int count, int max);
void	sa_sb(t_stack *stack, int flag);
void	ss(t_stack *a, t_stack *b);
void	pa_pb(t_stack *from, t_stack *to, t_cmd *cmd, int flag);
void	ra_rb(t_stack *stack, t_cmd *cmd, int flag);
void	rr(t_stack *a, t_stack *b, t_cmd *cmd);
void	rra_rrb(t_stack *stack, int flag);
void	rrr(t_stack *a, t_stack *b);
int		*sort_arr(t_stack *main, t_stack *sub, int count);
void	set_cmd(t_cmd *cmd);
int		check_ascending(t_stack *a, int count);
int		check_descending(t_stack *b, t_stack *a, int count);
void	error_handler(char *message, int error_code);
void	error_free(t_stack *stack1, t_stack *stack2);

#endif
