/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:32:35 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 19:30:44 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static void	pipe_counting(t_info *info)
{
	t_token_list	*cur;

	cur = info->list;
	while (cur)
	{
		if (cur->token.type == PIPE)
		{
			info->pipe_count = TRUE;
			break ;
		}
		cur = cur->next;
	}
}

int	main_init(char *line, t_info *info)
{
	add_history(line);
	ft_memset(info, 0, sizeof(t_info));
	info->list = make_token_list(tokenize(line));
	env_sub(info->list);
	info->ast = make_ast(info->list);
	if (syntax_check(info->ast) == FAIL)
	{
		update_exit_code(ft_strdup("258"));
		return (FAIL);
	}
	pipe_counting(info);
	ast_merge(info->ast);
	info->pl = pl_list(info->ast);
	return (SUCCESS);
}

int	set_init(char **envp, char **av)
{
	(void)av;
	init_env(envp);
	signal_init();
	setechoctl(1);
	print_art();
	return (SUCCESS);
}
