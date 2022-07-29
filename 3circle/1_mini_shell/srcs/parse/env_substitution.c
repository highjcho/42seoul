/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_substitution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:49:37 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/13 17:37:47 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

char	*ret_sub(char *str, char *sub, int pos1, int pos2)
{
	char	*ret;
	int		i;
	int		j;
	int		idx;

	i = -1;
	j = 0;
	idx = 0;
	ret = ft_calloc(ft_strlen(str) - pos2 + pos1 + ft_strlen(sub) + 1, 1);
	if (!sub)
		sub = ft_strdup("");
	sub = ft_strdup(sub);
	if (!ret)
		return (NULL);
	while (str[++i])
	{
		if (i < pos2 && i >= pos1)
			while (sub[j])
				ret[idx++] = sub[j++];
		else
			ret[idx++] = str[i];
	}
	free(sub);
	free(str);
	return (ret);
}

char	*substitution(char *s, int *p1, int p2, int i)
{
	int		j;
	char	*key;
	char	*sub;

	while (s[++i])
	{
		j = i + 1;
		if (s[i] == '$' && j <= p2)
		{
			if (s[j] == '?')
				return (ret_sub(s, get_env_value("?"), i, j + 1));
			if (s[j] && s[j] != '_' && !a(s[j]) && s[j] != '$' && s[j] != ' ')
				if ((s[j] != '\'' && s[j] != '\"') || !find_c(s + j + 1, s[j]))
					return (ret_sub(s, NULL, i, j + 1));
			while (j <= p2 && s[j] && (ft_isalnum(s[j]) || s[j] == '_'))
				j++;
			key = ft_substr(s, i + 1, j - i - 1);
			sub = get_env_value(key);
			*p1 += ft_strlen(sub) - 1;
			free(key);
			return (ret_sub(s, sub, i, j));
		}
	}
	return (s);
}

char	*env_check(char *str)
{
	int		i;
	int		tmp;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			tmp = i + 1;
			while (str[tmp] && str[tmp] != str[i])
				tmp++;
			if (str[tmp] == '\'')
			{
				str = quote_trim(str, i, tmp);
				i = tmp - 2;
			}
			else if (str[tmp] == '\"')
				str = double_quote_trim(str, &i, tmp);
		}
		else if (str[i] == '$')
			str = substitution(str, &i, ft_strlen(str), i - 1);
	}
	return (str);
}

int	env_sub(t_token_list *list)
{
	t_token_list	*cur;

	cur = list;
	while (cur)
	{
		if (cur->token.type == WORD && cur->token.str)
			cur->token.str = env_check(cur->token.str);
		cur = cur->next;
	}
	return (0);
}
