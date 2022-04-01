#include "checker.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	do_push_swap(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa_sb_checker(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		sa_sb_checker(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss_checker(a, b);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa_pb_checker(b, a);
	else if (!ft_strcmp(cmd, "pb\n"))
		pa_pb_checker(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra_rb_checker(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		ra_rb_checker(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr_checker(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra_rrb_checker(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rra_rrb_checker(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr_checker(a, b);
	else
		error_free(a, b);
}