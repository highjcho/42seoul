/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:12:46 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/19 09:12:46 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	double_free(char **src, char *msg, int error_code)
{
	int	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
	if (!msg)
		return ;
	error_handler(msg, error_code);
}

void	cmd_free(t_arg *args, char *msg, int error_code)
{
	free(args->cmd_path);
	double_free(args->cmd, msg, error_code);
}

void	all_free(t_arg *args, char *msg, int error_code)
{
	cmd_free(args, msg, error_code);
	double_free(args->path, msg, error_code);
}

void	error_handler(char *msg, int error_code)
{
	dup2(STDOUT_FILENO, STDOUT_FILENO);
	perror(msg);
	exit(error_code);
}