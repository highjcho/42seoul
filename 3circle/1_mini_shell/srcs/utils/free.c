/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:57:32 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 13:57:58 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	double_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_env_node(t_env_node *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	free_env(void)
{
	t_env_node	*cur;
	t_env_node	*tmp;

	cur = g_env->h_node.next;
	while (cur)
	{
		tmp = cur->next;
		free_env_node(cur);
		cur = tmp;
	}
}

void	free_ast(t_ast *node)
{
	if (node->data)
	{
		free(node->data);
		node->data = NULL;
	}
	if (node->av)
	{
		double_free(node->av);
		node->av = NULL;
	}
	if (node->file_name)
	{
		free(node->file_name);
		node->file_name = NULL;
	}
	free(node);
}
