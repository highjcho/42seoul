/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:40:26 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 15:40:27 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

void	ast_redirect_process(t_ast *ast);
int		here_doc(t_ast *pipeline, t_ast *node);
int		dup_fd(int from_fd, int to_fd);

#endif
