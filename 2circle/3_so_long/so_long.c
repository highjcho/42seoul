#include "so_long.h"

static int	count_width(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static void	set_map(t_game *game, char *file)
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
	line = get_next_line(fd);
	game->width = count_width(line);
	while(line)
	{
		tmp = ft_strjoin(tmp, line);
		line = get_next_line(fd);
		if (line && game->width != count_width(line))
			error_handler("Error\nso_long: invalid map format - not rec", errno);
	}
	close(fd);
	game->map = ft_split(game, tmp, '\n');
	if (!game->map)
		error_handler("so_long: allocate failed", errno);
}

static void	set_game(t_game *game)
{
	game->p.p = 0;
	game->p.x = 0;
	game->p.y = 0;
	game->p.move = 0;
	game->exit = 0;
	game->item = 0;
	game->map = NULL;
}

int	exit_game(t_game *game)
{
	double_free(game);
	mlx_destroy_window(game->mlx, game->win);
	printf("so_long: Escape success! You're total move count: %d", game->p.move);
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
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
	print_map(&game);
	mlx_hook(game.win, PRESS_KEY, 0, &play_game, &game);
	mlx_hook(game.win, MOUSE_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
}