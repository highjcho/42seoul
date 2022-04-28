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


	이동시에 할 거 
	무브 카운트 증가
	이전 P->0으로 바꾸고 
	p x,y좌표 바꾸고
	바뀐 좌표에 P로 바꾸고
	print_map 다시 실행 <- 이건 계속 위에 그리는건가,,? 아예 이미지 파괴는 안되겠지
	너무 다 그리는건 별론가;;? 걍 그 바뀐 두개만 바꿀까 그렇게 하자 ㅇㅇ

	exit 면 검사 해야댐 아이템 그래서 아이템 안 먹었으면 걍 출구 위에 또 새로 그리는거만 ㅇㅇ


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
