/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:41:24 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/13 17:33:53 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

int			add_env(char **export);
char		*get_env_value(char *key);
t_env_node	*get_env_node(char *key);
int			update_exit_code(char *exit_code);
int			find_c(char *s, char c);
int			check_key(char *key);
int			is_long(char *s);
long long	ft_atol(char *s);
void		double_free(char **str);
void		free_env_node(t_env_node *node);
void		free_env(void);
void		free_ast(t_ast *node);
void		all_free(t_info *info);
void		setechoctl(int flag);
char		*get_next_line(int fd);
void		print_art(void);
int			a(char c);

# define BUFFER_SIZE 4096

#endif
