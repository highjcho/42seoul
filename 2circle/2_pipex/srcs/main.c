/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:23:43 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/13 09:23:50 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	args;
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		error_handler("Pipex: Invalid argument");
	set_arg(argv, envp, &args);
	pipe(fd);
	pid = fork();
	if (pid < 0)
		all_free(&args, "Pipex: Fork error");
	pipex(&args, fd, &pid, envp);
	return (0);
}
