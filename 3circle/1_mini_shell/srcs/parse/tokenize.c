/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:50:16 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 13:59:12 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	quote(char *str, int *i, char c)
{
	int	tmp;

	tmp = *i;
	while (str[++(*i)])
	{
		if (str[*i] == c)
		{
			(*i)++;
			return ;
		}
	}
	*i = tmp + 1;
}

void	word(char *str, int *i)
{
	if (!str[*i])
		return ;
	while (str[(*i)])
	{
		if (str[*i] == ' ' || str[*i] == '|' || \
		str[*i] == '>' || str[*i] == '<')
			return ;
		if (str[*i] == '\'' || str[*i] == '\"')
			quote(str, i, str[*i]);
		(*i)++;
	}
}

void	redirection(char *str, int *i)
{
	if (str[(*i) + 1] == str[*i])
		(*i)++;
	(*i)++;
}

int	token_count(char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			ret++;
			i++;
		}
		if (str[i] == '<' || str[i] == '>')
			redirection(str, &i);
		if (str[i] == '\'' || str[i] == '\"')
			quote(str, &i, str[i]);
		if (str[i] != ' ' && str[i] != '\'' && str[i] != '\"' && \
		str[i] != '|' && str[i] != '>' && str[i] != '<')
			word(str, &i);
		while (str[i] == ' ')
			i++;
		ret++;
	}
	return (ret);
}

char	**tokenize(char *str)
{
	char	**tokens;

	if (token_count(str) == 0)
		return (NULL);
	tokens = ft_calloc((token_count(str) + 1), sizeof(char *));
	if (!tokens)
		return (NULL);
	tokens = make_token(str, tokens);
	return (tokens);
}
