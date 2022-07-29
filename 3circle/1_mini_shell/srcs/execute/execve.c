/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:11:19 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:11:20 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static int	set_path(void)
{
	if (g_env->path)
		free(g_env->path);
	g_env->path = ft_split(get_env_value("PATH"), ':');
	if (!g_env->path)
		return (FALSE);
	return (TRUE);
}

static int	need_to_make_path(t_ast *ast, char **envp)
{
	char	*tmp;
	int		i;

	i = -1;
	set_path();
	while (g_env->path && g_env->path[++i])
	{
		tmp = ft_strjoin("/", ast->av[0]);
		if (!tmp)
			exit(FAIL);
		ast->path = ft_strjoin(g_env->path[i], tmp);
		if (!ast->path)
			exit(FAIL);
		free(tmp);
		execve(ast->path, ast->av, envp);
		free(ast->path);
	}
	ft_putstr_fd("petitshell: ", STDERR_FILENO);
	ft_putstr_fd(ast->av[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	exit(COMMAND_FAIL);
}

static int	have_path(t_ast *ast, char **envp)
{
	if (!ft_strncmp("~/", ast->av[0], 2))
	{
		ast->path = ft_strjoin(get_env_value("HOME"), &ast->av[0][1]);
		if (!ast->path)
			exit(FAIL);
	}
	else
	{
		ast->path = ft_strdup(ast->av[0]);
		if (!ast->path)
			exit(FAIL);
	}
	execve(ast->path, ast->av, envp);
	ft_putstr_fd("petitshell: ", STDERR_FILENO);
	ft_putstr_fd(ast->av[0], STDERR_FILENO);
	ft_putendl_fd(": command not found\n", STDERR_FILENO);
	exit(COMMAND_FAIL);
}

static void	do_child_proc(t_ast *ast, char **envp, int *fd)
{
	close(fd[0]);
	dup_fd(ast->in_fd, STDIN_FILENO);
	dup_fd(ast->out_fd, STDOUT_FILENO);
	if (ast->right->av[0][0] == 0)
		exit(EXIT_SUCCESS);
	if (find_c(ast->right->av[0], '/'))
		have_path(ast->right, envp);
	else
		need_to_make_path(ast->right, envp);
}

int	execute_non_builtin(t_ast *ast, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	pipe(fd);
	if (ast->out_fd == 0)
		ast->out_fd = fd[1];
	pid = fork();
	if (pid < 0)
		return (FALSE);
	if (pid == 0)
		do_child_proc(ast, envp, fd);
	close(fd[1]);
	wait(&status);
	if ((status & 255) == 0)
		update_exit_code(ft_itoa(status >> 8));
	else
		update_exit_code(ft_itoa(status + 128));
	return (fd[0]);
}
