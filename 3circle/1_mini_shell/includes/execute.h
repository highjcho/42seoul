/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:41:06 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 15:41:07 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

int	execute_cmd(t_ast *ast, char **envp, int flag);
int	execute_one_builtin(t_ast *ast);
int	execute_builtin(t_ast *ast);
int	execute_non_builtin(t_ast *ast, char **envp);
int	fork_process(void);

#endif
