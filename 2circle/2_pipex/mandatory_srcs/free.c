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

void	single_free(char *src1, char *src2, char *msg)
{
	free(src1);
	if (src2)
		free(src2);
	error_handler(msg, 1);
}

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

void	all_free(t_arg *args, char *msg, int error_code)
{
	free(args->infile);
	free(args->outfile);
	free(args->path);
	double_free(args->cmd, msg, error_code);
}

void	error_handler(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}
