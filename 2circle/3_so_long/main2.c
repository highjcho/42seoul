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