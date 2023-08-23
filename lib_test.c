#include "include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	*img;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "HOLA");
	img = (t_img *) malloc (sizeof(t_img) * 1);
	int i = 1;
	while (i < 100)
	{
		mlx_pixel_put(mlx, win, 100, i, 0xFFFF00);
		mlx_pixel_put(mlx, win, i++, 100, 0xFF00FF);
	}
	img->img_ptr = mlx_xpm_file_to_image(mlx, "assets/sl_road.xpm", &img->img_w, &img->img_h);

	img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->img_bpp, &img->img_size, &img->img_endian);

	mlx_put_image_to_window(mlx, win, img->img_ptr, 10, 10);
	mlx_loop(mlx);
	//mlx_destroy(mlx);
}
