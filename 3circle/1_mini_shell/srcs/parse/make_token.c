/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:59:30 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 14:57:11 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static	int	token_check(char *str, char **tokens, int *i, int *j)
{
	int	tmp;

	while (str[*i] == ' ')
		(*i)++;
	tmp = *i;
	if (str[*i] == '|')
	{
		tokens[(*j)++] = ft_strdup("|");
		(*i)++;
		tmp++;
	}
	if (str[*i] == '<' || str[*i] == '>')
	{
		redirection(str, i);
		tokens[(*j)++] = ft_substr(str, tmp, (*i) - tmp);
		tmp = *i;
	}
	return (tmp);
}

char	**make_token(char *str, char **tokens)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (str[i])
	{
		tmp = token_check(str, tokens, &i, &j);
		if (str[i] == '\'' || str[i] == '\"')
			quote(str, &i, str[i]);
		if (str[i] != ' ' && str[i] != '\'' && str[i] != '\"' \
		&& str[i] != '|' && str[i] != '>' && str[i] != '<')
			word(str, &i);
		if (i != tmp)
			tokens[j++] = ft_substr(str, tmp, i - tmp);
	}
	tokens[token_count(str)] = 0;
	return (tokens);
}
