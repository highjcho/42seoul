/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:38:43 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 08:40:42 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int		ft_strlen(char *s);

#endif
