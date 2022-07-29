/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelinelist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:48:46 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 12:49:00 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_pl_list	*make_pl_list(t_ast *ast, t_pl_list *node)
{
	t_pl_list	*cur;

	cur = node;
	if (ast->type == PIPELINE)
	{
		cur = ft_calloc(sizeof(t_pl_list), 1);
		cur->pipeline = ast;
		node->next = cur;
	}
	if (ast->left)
		cur = make_pl_list(ast->left, cur);
	if (ast->right)
		cur = make_pl_list(ast->right, cur);
	return (cur);
}

t_pl_list	*pl_list(t_ast *ast)
{
	t_pl_list	*list;

	list = ft_calloc(sizeof(t_pl_list), 1);
	make_pl_list(ast, list);
	return (list);
}
