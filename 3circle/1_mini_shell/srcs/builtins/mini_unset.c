/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:10:23 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:10:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static t_env_node	*find_prev_env(t_env_node *node, char *key)
{
	if (!node || !(node->next))
		return (NULL);
	while (ft_strcmp(node->next->key, key))
	{
		node = node->next;
		if (!node->next)
			return (NULL);
	}
	return (node);
}

static void	disconnect_node(t_env_node *prev, t_env_node *cur)
{
	prev->next = cur->next;
	cur->next = NULL;
	free_env_node(cur);
}

int	mini_unset(char **cmd)
{
	t_env_node	*prev;
	int			i;
	int			flag;

	i = 0;
	flag = 0;
	while (cmd[++i])
	{
		if (!check_key(cmd[i]))
		{
			printf("unset: '%s': not a valid identifier\n", cmd[i]);
			flag = 1;
			continue ;
		}
		prev = find_prev_env(g_env->h_node.next, cmd[i]);
		if (!prev)
			continue ;
		disconnect_node(prev, prev->next);
	}
	if (flag)
		return (FAIL);
	return (SUCCESS);
}
