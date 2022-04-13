/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:24:02 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/13 09:24:02 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	all_free(t_arg *args, char *msg)
{
	double_free(args->cmd1, args->cmd2, 0);
	free(args->cmd1_path);
	free(args->cmd2_path);
	free(args->infile);
	free(args->outfile);
	error_handler(msg);
}

void	single_free(char *src, char *msg)
{
	free(src);
	error_handler(msg);
}

void	double_free(char **src1, char **src2, char *msg)
{
	int	i;

	i = 0;
	while (src1[i])
	{
		free(src1[i]);
		i++;
	}
	free(src1);
	i = 0;
	if (src2)
	{
		while (src2[i])
		{
			free(src2[i]);
			i++;
		}
		free(src2);
	}
	if (!msg)
		return ;
	error_handler(msg);
}

void	error_handler(char *msg)
{
	perror(msg);
	exit(1);
}
