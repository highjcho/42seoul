/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:44:29 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 12:44:30 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	ast_cmd_merge(t_ast *node, t_ast *right)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (right == NULL)
	{
		node->ac = 1;
		node->av = malloc((node->ac + 1) * sizeof(char *));
		node->av[0] = ft_strdup(node->data);
		node->av[1] = 0;
	}
	else
	{
		node->ac = right->ac + 1;
		node->av = malloc((node->ac + 1) * sizeof(char *));
		node->av[++i] = ft_strdup(node->data);
		while (right->av[++j])
			node->av[++i] = ft_strdup(right->av[j]);
		node->av[node->ac] = 0;
		free_ast(node->right);
		node->right = NULL;
	}
}

void	ast_merge(t_ast *ast)
{
	if (ast->left)
		ast_merge(ast->left);
	if (ast->right)
		ast_merge(ast->right);
	if (ast->type == REDIRECT)
	{
		if (ast->left)
		{
			ast->file_name = ft_strdup(ast->left->data);
			free_ast(ast->left);
			ast->left = NULL;
		}
	}
	else if (ast->type == WORD)
		ast_cmd_merge(ast, ast->right);
	return ;
}
