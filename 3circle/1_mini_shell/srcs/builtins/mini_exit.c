/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:10:00 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:10:01 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	mini_exit(t_ast *ast)
{
	if (ast->ac >= 2 && !is_long(ast->av[1]))
	{
		printf("exit: %s: numeric argument required\nexit\n", ast->av[1]);
		update_exit_code(ft_strdup("255"));
		exit(ft_atol(g_env->exit_code->value));
	}
	else if (ast->ac > 2)
	{
		printf("exit: too many arguments\n");
		update_exit_code(ft_strdup("1"));
		return (FAIL);
	}
	printf("exit\n");
	if (ast->ac == 1)
		exit(EXIT_SUCCESS);
	exit(ft_atol(ast->av[1]));
	return (FALSE);
}
