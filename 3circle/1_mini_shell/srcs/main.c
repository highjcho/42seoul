/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:59:15 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/14 12:59:18 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	execute_line(t_pl_list *list, char **envp, int count)
{
	int	next_in_fd;
	int	flag;

	next_in_fd = STDIN_FILENO;
	flag = FALSE;
	while (list)
	{
		list->pipeline->in_fd = next_in_fd;
		if (!list->next)
			list->pipeline->out_fd = 1;
		ast_redirect_process(list->pipeline);
		if (list->pipeline->in_fd == -1 || list->pipeline->out_fd == -1)
		{
			update_exit_code(ft_strdup("1"));
			list = list->next;
			next_in_fd = fork_process();
			continue ;
		}
		next_in_fd = execute_cmd(list->pipeline, envp, count);
		list = list->next;
	}
	if (next_in_fd != STDIN_FILENO)
		close(next_in_fd);
}

int	main(int ac, char **av, char **envp)
{
	char			*line;
	t_info			info;

	if (ac != 1)
		return (0);
	set_init(envp, av);
	while (1)
	{
		line = readline("petitshell> ");
		if (!line)
		{
			printf("petitshell> exit\n");
			exit(EXIT_SUCCESS);
		}
		else if (!*line || main_init(line, &info) == FAIL)
		{
			free(line);
			continue ;
		}
		execute_line(info.pl->next, envp, info.pipe_count);
		all_free(&info);
		free(line);
	}
	return (0);
}
