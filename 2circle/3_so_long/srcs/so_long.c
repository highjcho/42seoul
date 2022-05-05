/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:30:05 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/05/03 09:30:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *g)
{
	g->p.p = 0;
	g->p.x = 0;
	g->p.y = 0;
	g->p.moves = 0;
	g->exit = 0;
	g->item = 0;
	g->map = NULL;
	g->i.p = NULL;
	g->i.w = NULL;
	g->i.r = NULL;
	g->i.i = NULL;
	g->i.c = NULL;
	g->i.e = NULL;
}

static int	count_width(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static void	set_map(t_game *g, char *file)
{
	char	*tmp;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handler("so_long: open failed", errno);
	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		error_handler("so_long: allocate failed", errno);
	line = get_next_line(fd, tmp);
	g->wid = count_width(line);
	while (line)
	{
		tmp = ft_strjoin(tmp, line);
		if (!tmp)
			error_handler("so_long: allocate failed", errno);
		line = get_next_line(fd, tmp);
		check_rectangular(g, count_width(line), tmp, line);
	}
	close(fd);
	g->map = ft_split(g, tmp, '\n');
	if (!g->map)
		error_free("so_long: allocate failed", tmp, NULL, errno);
	free(tmp);
}

int	force_quit(t_game *g)
{
	destroy_all(g);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_handler("so_long: invalid arguments", EXIT_FAILURE);
	init_game(&game);
	set_map(&game, av[1]);
	check_map(&game);
	game.m = mlx_init();
	if (!game.m)
	{
		map_free(&game);
		error_handler("so_long: mlx connect fail", errno);
	}
	game.w = mlx_new_window(game.m, game.wid * 64, game.hei * 64, "so_long");
	if (!game.w)
	{
		map_free(&game);
		error_handler("so_long: window create fail", errno);
	}
	print_map(&game);
	mlx_hook(game.w, PRESS_KEY, 0, &play_game, &game);
	mlx_hook(game.w, MOUSE_EXIT, 0, &force_quit, &game);
	mlx_loop(game.m);
	return (0);
}
