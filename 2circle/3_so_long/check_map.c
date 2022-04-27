#include "so_long.h"

static void	check_outside(t_game *game)
{
	int	i;

	i = -1;
	while(++i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			error_handler("Error\nso_long: invalid map format(not proper outside)", errno);
	}
	i = -1;
	while(++i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1') // 벽 중복 되는 부분 검사 안할 지 확인 필요
			error_handler("Error\nso_long: invaild map format(not proper outside)", errno);
	}
}

static void	check_inside(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->height)
	{
		j = 0;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->p++;
				game->p_x = i;
				game->p_y = j;
			}
			else if (game->map[i][j] == 'C')
				game->item++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				error_handler("Error\nso_long: invalid map format(invalid arguments)", errno);
		}
	}
}

void	check_map(t_game *game)
{
	check_outside(game);
	check_inside(game);
	if (game->p != 1 || !game->item || !game->exit)
		error_handler("Error\nso_long: invalid map format(count fail)", errno);
}