/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:16:56 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/19 09:16:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_arg
{
	char	**path;
	char	*cmd_path;
	char	**cmd;
	int		here_doc;
	int		cmd_err;
}	t_arg;

int		pipex(t_arg *args, char **envp, int read_fd);
void	set_path(t_arg *args, char **envp);
void	set_cmd(t_arg *args, char *cmd);
void	output(t_arg *args, char *cmd, char **envp, int read_fd);
void	cmd_free(t_arg *args, char *msg, int error_code);
void	double_free(char **cmd, char *msg, int error_code);
void	all_free(t_arg *args, char *msg, int error_code);
void	error_handler(char *msg, int error_code);

#endif
