/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:25:35 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/13 09:25:36 by hyunjcho         ###   ########.fr       */
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
# include "../libft/libft.h"

typedef struct s_arg
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_arg;

void	pipex(t_arg *args, int *fd, pid_t *pid, char **envp);
void	set_arg(char **argv, char **envp, t_arg *args);
void	single_free(char *src, char *msg);
void	double_free(char **free1, char **free2, char *msg);
void	all_free(t_arg *args, char *msg);
void	error_handler(char *msg);

#endif
