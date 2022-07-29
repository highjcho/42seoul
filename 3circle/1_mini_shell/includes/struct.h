/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:40:38 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 15:40:39 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

enum e_token_type
{
	WORD,
	REDIRECT,
	PIPELINE,
	PIPE,
};

typedef struct s_token
{
	char				*str;
	enum e_token_type	type;
}	t_token;

typedef struct s_token_list
{
	struct s_token_list	*next;
	t_token				token;
}	t_token_list;

typedef struct s_ast
{
	struct s_ast		*left;
	struct s_ast		*right;
	char				*data;
	int					ac;
	char				**av;
	char				*path;
	char				*file_name;
	int					in_fd;
	int					out_fd;
	enum e_token_type	type;
}	t_ast;

typedef struct s_pl_list
{
	struct s_ast		*pipeline;
	struct s_pl_list	*next;
}	t_pl_list;

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_env
{
	t_env_node	h_node;
	t_env_node	*pwd;
	t_env_node	*old_pwd;
	t_env_node	*exit_code;
	char		**path;
}	t_env;

typedef struct s_info
{
	struct s_token_list	*list;
	struct s_env		*env;
	struct s_ast		*ast;
	struct s_pl_list	*pl;
	int					pipe_count;
}	t_info;

t_env	*g_env;

#endif