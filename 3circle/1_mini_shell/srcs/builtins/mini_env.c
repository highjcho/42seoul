/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:09:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:09:58 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static int	env_error_print(char *argument)
{
	ft_putstr_fd("petitshell: env: ", STDERR_FILENO);
	ft_putstr_fd(argument, STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	return (COMMAND_FAIL);
}

int	mini_env(t_ast *ast)
{
	t_env_node	*cur;

	if (ast->ac != 1)
		return (env_error_print(ast->av[1]));
	cur = g_env->h_node.next;
	while (cur)
	{
		if (cur->value == g_env->exit_code->value)
		{
			cur = cur->next;
			continue ;
		}
		printf("%s=%s\n", cur->key, cur->value);
		cur = cur->next;
	}
	return (SUCCESS);
}
