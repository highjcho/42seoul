/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:34:16 by jonkim            #+#    #+#             */
/*   Updated: 2022/06/09 12:37:38 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signal.h"

static void	handle_sigint(pid_t pid)
{
	if (pid == -1)
	{	
		rl_on_new_line();
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
		update_exit_code(ft_strdup("1"));
	}
	else
	{
		update_exit_code(ft_strdup("130"));
		printf("^C\n");
	}
}

static void	handle_sigquit(pid_t pid)
{
	if (pid == -1)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		update_exit_code(ft_strdup("131"));
		printf("^\\Quit: 3\n");
	}
}

void	handle_signal(int signum)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signum == SIGINT)
		handle_sigint(pid);
	else if (signum == SIGQUIT)
		handle_sigquit(pid);
}

void	handle_signal_heredoc(int signum)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (pid == -1)
	{
		if (signum == SIGINT)
		{
			update_exit_code(ft_strdup("1"));
			exit(EXIT_FAILURE);
		}
		else if (signum == SIGQUIT)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
	else
	{
		if (signum == SIGINT)
			printf("\n");
	}
}

void	signal_init(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}
