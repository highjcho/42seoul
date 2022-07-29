/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:10:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:10:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static int	empty_value(char **export)
{
	export[1] = ft_strdup("");
	if (!export[1])
	{
		free(export[0]);
		free(export);
		return (FALSE);
	}
	return (TRUE);
}

int	mini_export(char **cmd)
{
	char	**export;
	int		i;

	i = 0;
	while (cmd[++i])
	{
		if (!find_c(cmd[i], '='))
			continue ;
		export = ft_split(cmd[i], '=');
		if (!export)
			return (FAIL);
		if (!check_key(export[0]))
		{
			printf("petitshell: export '%s': not a valid identifier\n", cmd[1]);
			double_free(export);
			continue ;
		}
		if (export[1] == NULL)
			if (!empty_value(export))
				return (FAIL);
		if (!add_env(export))
			return (FAIL);
	}
	return (SUCCESS);
}
