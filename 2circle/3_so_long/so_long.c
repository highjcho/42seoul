#include "so_long.h"

static int	count_width(char *s)
{
	int	i;

	i = 0;
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
	while(line)
	{
		tmp = ft_strjoin(tmp, line);
		if (!tmp)
			error_free("so_long: allocate failed", line, NULL, errno);
		line = get_next_line(fd, tmp);
		if (line && g->wid != count_width(line))
			error_handler("Error\nso_long: invalid map format", errno);
	}
	close(fd);
	g->map = ft_split(g, tmp, '\n');
	if (!g->map)
		error_free("so_long: allocate failed", tmp, NULL, errno);
}

static void	set_game(t_game *g)
{
	g->p.p = 0;
	g->p.x = 0;
	g->p.y = 0;
	g->p.move = 0;
	g->exit = 0;
	g->item = 0;
	g->map = NULL;
}

int	exit_game(t_game *g)
{
	map_free(g);
	mlx_destroy_window(g->m, g->w);
	printf("so_long: Escape uccess! You're total move count: %d", g->p.move);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_handler("so_long: invalid arguments", errno);
	set_game(&game);
	set_map(&game, av[1]);
	check_map(&game);
	game.m = mlx_init(); // 이건 무 처리가 있나..?
	game.w = mlx_new_window(game.m, game.wid * 64, game.hei * 64, "so_long"); // 오류 처리 했눈지?
	if (!game.w)
	{
		map_free(&game);
		error_handler("so_long: window create fail", errno);
	}
	print_map(&game);
	mlx_hook(game.w, PRESS_KEY, 0, &play_game, &game);
	mlx_hook(game.w, MOUSE_EXIT, 0, &exit_game, &game);
	mlx_loop(game.m);
}