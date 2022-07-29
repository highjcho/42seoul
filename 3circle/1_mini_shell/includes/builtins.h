/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:40:56 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 15:40:58 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int	mini_echo(char **cmd);
int	mini_cd(char **cmd);
int	mini_pwd(void);
int	mini_export(char **cmd);
int	mini_unset(char **cmd);
int	mini_env(t_ast *ast);
int	mini_exit(t_ast *ast);

#endif
