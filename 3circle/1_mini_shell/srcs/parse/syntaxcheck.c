/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:49:58 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/13 18:53:47 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	syntax_error_print(char *str)
{
	printf("syntax error near unexpected token \'%s\'\n", str);
	return (FAIL);
}

int	recur_syntax_check(t_ast *ast)
{
	if (!ast || ast->type == WORD)
		return (SUCCESS);
	if (ast->type == PIPE)
		if (ast->left == NULL && ast->right == NULL)
			return (syntax_error_print(ast->data));
	if (ast->type == REDIRECT)
		if (ast->left == NULL)
			return (syntax_error_print(ast->data));
	if (ast->type == PIPELINE)
		if (ast->left == NULL && ast ->right == NULL)
			return (syntax_error_print("|"));
	if (recur_syntax_check(ast->left))
		return (FAIL);
	else if (recur_syntax_check(ast->right))
		return (FAIL);
	else
		return (SUCCESS);
}

int	syntax_check(t_ast *ast)
{
	if (ast->type == PIPE && ast->right == NULL)
		return (syntax_error_print(ast->data));
	if (recur_syntax_check(ast->left))
		return (FAIL);
	else if (recur_syntax_check(ast->right))
		return (FAIL);
	else
		return (SUCCESS);
}
