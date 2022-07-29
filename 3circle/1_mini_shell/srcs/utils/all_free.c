/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:39:30 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 12:40:03 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static void	free_token_list(t_token_list *list)
{
	t_token_list	*cur;
	t_token_list	*tmp;

	cur = list;
	while (cur)
	{
		tmp = cur;
		if (cur->token.str)
		{
			free(cur->token.str);
			cur->token.str = NULL;
		}
		cur = cur->next;
		free(tmp);
	}
}

static void	free_pl_list(t_pl_list *pl_list)
{
	t_pl_list	*cur;
	t_pl_list	*tmp;

	cur = pl_list;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

static void	free_ast_all_free(t_ast	*ast)
{
	if (ast->left)
		free_ast_all_free(ast->left);
	if (ast->right)
		free_ast_all_free(ast->right);
	if (ast)
		free_ast(ast);
}

void	all_free(t_info *info)
{
	if (info->list)
	{
		free_token_list(info->list);
		info->list = NULL;
	}
	if (info->ast)
	{
		free_ast_all_free(info->ast);
		info->ast = NULL;
	}	
	if (info->pl)
	{
		free_pl_list(info->pl);
		info->pl = NULL;
	}
}
