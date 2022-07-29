/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:11:12 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:11:14 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static int	do_builtin(t_ast *ast, int kind)
{
	int	check;

	if (kind == 1)
		check = mini_echo(ast->av);
	else if (kind == 2)
		check = mini_cd(ast->av);
	else if (kind == 3)
		check = mini_pwd();
	else if (kind == 4)
		check = mini_export(ast->av);
	else if (kind == 5)
		check = mini_unset(ast->av);
	else if (kind == 6)
		check = mini_env(ast);
	else
		check = mini_exit(ast);
	return (check);
}

static int	write_pipe(t_ast *ast, int kind)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) < 0)
		return (FALSE);
	if (ast->out_fd == 0)
		ast->out_fd = fd[1];
	pid = fork();
	if (pid < 0)
		return (FALSE);
	if (pid == 0)
	{
		close(fd[0]);
		dup_fd(ast->in_fd, STDIN_FILENO);
		dup_fd(ast->out_fd, STDOUT_FILENO);
		exit(do_builtin(ast->right, kind));
	}
	close(fd[1]);
	wait(&status);
	if (status >> 8 == FAIL)
		return (FAIL);
	else if (status >> 8 == COMMAND_FAIL)
		return (COMMAND_FAIL);
	return (fd[0]);
}

int	execute_builtin(t_ast *ast)
{
	if (ast->right)
	{
		if (!ft_strcmp(ast->right->av[0], "echo"))
			return (write_pipe(ast, 1));
		else if (!ft_strcmp(ast->right->av[0], "cd"))
			return (write_pipe(ast, 2));
		else if (!ft_strcmp(ast->right->av[0], "pwd"))
			return (write_pipe(ast, 3));
		else if (!ft_strcmp(ast->right->av[0], "export"))
			return (write_pipe(ast, 4));
		else if (!ft_strcmp(ast->right->av[0], "unset"))
			return (write_pipe(ast, 5));
		else if (!ft_strcmp(ast->right->av[0], "env"))
			return (write_pipe(ast, 6));
		else if (!ft_strcmp(ast->right->av[0], "exit"))
			return (write_pipe(ast, 7));
	}
	return (-1);
}

int	execute_one_builtin(t_ast *ast)
{
	if (ast->right)
	{
		if (!ft_strcmp(ast->right->av[0], "cd"))
			return (mini_cd(ast->right->av));
		else if (!ft_strcmp(ast->right->av[0], "export"))
			return (mini_export(ast->right->av));
		else if (!ft_strcmp(ast->right->av[0], "unset"))
			return (mini_unset(ast->right->av));
		else if (!ft_strcmp(ast->right->av[0], "exit"))
			return (mini_exit(ast->right));
	}
	return (-1);
}
