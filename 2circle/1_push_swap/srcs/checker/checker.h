#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../push_swap/push_swap.h"

# define BUFFER 10

char	*get_next_cmd(int *flag);
void	do_push_swap(t_stack *a, t_stack *b, char *cmd);
void	sa_sb_checker(t_stack *stack);
void	ss_checker(t_stack *a, t_stack *b);
void	pa_pb_checker(t_stack *from, t_stack *to);
void	ra_rb_checker(t_stack *stack);
void	rr_checker(t_stack *a, t_stack *b);
void	rra_rrb_checker(t_stack *stack);
void	rrr_checker(t_stack *a, t_stack *b);
char	*ft_calloc(int	count);

#endif