/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:12:22 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/13 12:43:03 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static int	update_value(char **export)
{
	t_env_node	*cur;

	cur = get_env_node(export[0]);
	free(cur->value);
	free(export[0]);
	cur->value = export[1];
	return (TRUE);
}

int	add_env(char **export)
{
	t_env_node	*prev;
	t_env_node	*new;

	if (get_env_node(export[0]))
		return (update_value(export));
	new = malloc(sizeof(t_env_node));
	if (!new)
	{
		double_free(export);
		return (FALSE);
	}
	prev = &(g_env->h_node);
	while (prev->next)
		prev = prev->next;
	prev->next = new;
	new->key = ft_strdup(export[0]);
	new->value = ft_strdup(export[1]);
	double_free(export);
	new->next = NULL;
	return (TRUE);
}

int	update_exit_code(char *exit_code)
{
	free(g_env->exit_code->value);
	g_env->exit_code->value = exit_code;
	if (!g_env->exit_code->value)
		return (FALSE);
	return (TRUE);
}

char	*get_env_value(char *key)
{
	t_env_node	*ret;

	if (!key)
		return ("$");
	ret = g_env->h_node.next;
	while (ret)
	{
		if (!ft_strcmp(key, ret->key))
			return (ret->value);
		ret = ret->next;
	}
	return (NULL);
}

t_env_node	*get_env_node(char *key)
{
	t_env_node	*ret;

	if (!key)
		return (NULL);
	ret = g_env->h_node.next;
	while (ret)
	{
		if (!ft_strcmp(key, ret->key))
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}
