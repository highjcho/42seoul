/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:11:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 11:11:55 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirect.h"

static void	get_line(char *delimiter, char *line, int out_fd)
{
	while (line)
	{
		if (!ft_strcmp(delimiter, line))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, out_fd);
		free(line);
		line = readline("> ");
	}
}

int	here_doc(t_ast *pipeline, t_ast *node)
{
	pid_t	pid;
	int		fd[2];
	int		status;
	char	*line;

	if (pipe(fd) < 0)
		return (FALSE);
	pid = fork();
	signal(SIGINT, handle_signal_heredoc);
	signal(SIGQUIT, handle_signal_heredoc);
	if (pid < 0)
		return (FALSE);
	if (pid == 0)
	{
		close(fd[0]);
		line = readline("> ");
		get_line(node->file_name, line, fd[1]);
		exit(EXIT_SUCCESS);
	}
	close(fd[1]);
	wait(&status);
	pipeline->in_fd = fd[0];
	return (TRUE);
}
