/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:49:49 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 12:44:45 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	redirection_check(t_ast *node)
{
	if (node->right)
		return (redirection_check(node->right));
	if (node->left)
		return (1);
	return (0);
}

t_ast	*add_pl_node(t_ast *parent, t_ast *child)
{
	if (child->type == REDIRECT)
	{
		if (parent->left == NULL)
			parent->left = child;
		else
			add_ast_node(parent->left, child);
	}
	else if (child->type == WORD)
	{
		if (parent->left != NULL && !redirection_check(parent->left))
			add_ast_node(parent->left, child);
		else if (parent->right == NULL)
			parent->right = child;
		else
			add_ast_node(parent->right, child);
	}
	else
	{
		if (child->left == NULL)
			child->left = parent;
		else
			child->right = parent;
		return (child);
	}
	return (parent);
}

t_ast	*add_pipe_node(t_ast *parent, t_ast *child)
{
	if (child->type == REDIRECT || child->type == WORD)
	{
		if (parent->right == NULL)
		{
			parent->right = make_ast_node(NULL);
			add_ast_node(parent, child);
		}
		else
			add_ast_node(parent->right, child);
	}
	else
	{
		if (parent->right == NULL)
			parent->right = child;
		else
		{
			child->left = parent ->left;
			parent->left = parent ->right;
			child->right = parent;
			parent->right = NULL;
			return (child);
		}
	}
	return (parent);
}

t_ast	*add_redirect_node(t_ast *parent, t_ast *child)
{
	if (child->type == REDIRECT)
	{
		if (parent->right == NULL)
			parent->right = child;
		else
			add_ast_node(parent->right, child);
	}
	else
	{
		if (parent->left == NULL)
			parent->left = child;
		else
			add_ast_node(parent->right, child);
	}
	return (parent);
}

t_ast	*add_cmd_node(t_ast *parent, t_ast *child)
{
	if (parent->right == NULL)
		parent->right = child;
	else
		add_ast_node(parent->right, child);
	return (parent);
}
