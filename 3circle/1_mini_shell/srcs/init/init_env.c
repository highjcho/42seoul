/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:11:33 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:11:34 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"

static int	init_add_env(char **export)
{
	t_env_node	*prev;
	t_env_node	*new;

	new = ft_calloc(1, sizeof(t_env_node));
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
	if (!ft_strcmp(new->key, "PWD"))
		g_env->pwd = new;
	if (!ft_strcmp(new->key, "OLDPWD"))
		g_env->old_pwd = new;
	return (TRUE);
}

static int	set_env(char **envp)
{
	char		**export;
	int			i;

	i = -1;
	while (envp[++i])
	{
		export = ft_split(envp[i], '=');
		if (!export)
			return (FALSE);
		if (!init_add_env(export))
		{
			free_env();
			return (FALSE);
		}
	}
	export = ft_split("?=0", '=');
	if (!export)
		return (FALSE);
	if (!add_env(export))
	{
		free_env();
		return (FALSE);
	}
	g_env->exit_code = get_env_node("?");
	return (TRUE);
}

int	init_env(char **envp)
{
	g_env = ft_calloc(1, sizeof(t_env));
	if (!set_env(envp))
		return (FAIL);
	return (SUCCESS);
}
