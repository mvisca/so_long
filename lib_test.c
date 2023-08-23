#include "include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	*img;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 320, 320, "HOLA");

	img = (t_img *) malloc (sizeof(t_img) * 1);
	img->img_ptr = mlx_xpm_file_to_image(mlx, "assets/sl_road.xpm", &img->img_w, &img->img_h);
	img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->img_bpp, &img->img_size, &img->img_endian);

	int i = 0;
	while (i < 10)
	{
		int j = 0;
		while (j < 10)
			mlx_put_image_to_window(mlx, win, img->img_ptr, 32 * i, 32 * j++);
		i++;
	}

	i = 1;
	int ex = 0;
	int limit = 32 * 2;
	while (ex < 32)
	{
		while (i < limit)
		{
			mlx_pixel_put(mlx, win, limit, i, 0xFFFF00);
			mlx_pixel_put(mlx, win, i, limit, 0xFF00FF);
			i++;
		}
		i = 1;
		ex++;
		limit++; 
	}
	mlx_loop(mlx);
	//mlx_destroy(mlx);
}
