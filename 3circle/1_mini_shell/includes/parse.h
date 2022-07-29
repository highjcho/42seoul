/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:40:23 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/13 17:37:51 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

char			**tokenize(char *str);
t_token_list	*make_token_list(char **tokens);
t_ast			*add_pl_node(t_ast *parent, t_ast *child);
t_ast			*add_pipe_node(t_ast *parent, t_ast *child);
t_ast			*add_redirect_node(t_ast *parent, t_ast *child);
t_ast			*add_cmd_node(t_ast *parent, t_ast *child);
t_ast			*add_ast_node(t_ast *parent, t_ast *child);
t_ast			*make_ast(t_token_list *list);
t_ast			*make_ast_node(t_token_list *list);
int				env_sub(t_token_list *list);
int				syntax_check(t_ast *ast);
void			ast_merge(t_ast *ast);
t_pl_list		*pl_list(t_ast *ast);
char			*quote_trim(char *str, int pos1, int pos2);
char			*quote_check(char *str);
char			**make_token(char *str, char **tokens);
void			quote(char *str, int *i, char c);
void			word(char *str, int *i);
void			redirection(char *str, int *i);
int				token_count(char *str);
char			*env_check(char *str);
char			*double_quote_trim(char *str, int *pos1, int pos2);
char			*quote_trim(char *str, int pos1, int pos2);
char			*substitution(char *str, int *pos1, int pos2, int i);

#endif
