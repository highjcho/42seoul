#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./imgs/path.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./imgs/item.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./imgs/player.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_loop(mlx);
	return (0);
}

	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			printf("%c", game->map[i][j]);
		}
		printf("\n");
	}


내일 할 거
1. 42헤더 넣기
2. 놈 오류 찾기
3. 맵 오류 다 검사하기 
	1. 0,1,C,E,P 외에 다른 글자 들어왔을 경우
	2. 벽이 다 1로 둘러싸여있는지
	3. player != 1, c > 0, e > 0 인지 확인
	4. 직사각형인지
4. 보너스 해볼까? 2개만?
	void	ft_print_moves(t_game *game)
{
	char	*text;
	int		moves;

	moves = game->moves;
	text = ft_itoa(moves);
	game->text = text;
	mlx_string_put(game->mlx_ptr, game->win_ptr, 48, 20, YELLOW, text);
	free(text);
}
	strin_put함수 이용해서 text 찍어주는데 itoa 사용하면 됨. 48,20은 적당한 위치 찾아주면 될거 같고
	적은 랜덤 위치 (지최님 경우 -> x % 7 = 3, y % 5 = 2 인 경우에 적 생성)에
	좌표가 'C'라면 'V'로 바꾸고 이미지 그려주고
	무브에서 if map == 'V'면 you died 찍고 게임 끝내는 것으로 ㅇㅇ.
	이경우 변경해야 하는거
	ft_itoa에 대한 에러처리(map free 해줘야함)
	text 할당 오류에 대한 에러처리
	구조체에 text 추가 해야함


void	print_move_count(t_game *game)
{
	game->p.move++;
	printf("total moves: %d\n", game->p.move);
	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			printf("%c", game->map[i][j]);
		}
		printf("\n");
	}
}
