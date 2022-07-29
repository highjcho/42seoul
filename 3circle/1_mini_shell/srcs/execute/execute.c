/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:11:16 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:11:17 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

int	execute_cmd(t_ast *ast, char **envp, int flag)
{
	int	result;

	result = -1;
	if (flag == FALSE)
		result = execute_one_builtin(ast);
	if (result == -1)
		result = execute_builtin(ast);
	if (result == -1)
		return (execute_non_builtin(ast, envp));
	if (result == FAIL || result == COMMAND_FAIL)
	{
		if (result == FAIL)
			update_exit_code(ft_strdup("1"));
		else
			update_exit_code(ft_strdup("127"));
		return (STDIN_FILENO);
	}
	update_exit_code(ft_strdup("0"));
	return (result);
}
