#include "include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	*img;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 320, 320, "HOLA");

	// crea struct con los datos para mostrar imagen
	img = (t_img *) malloc (sizeof(t_img) * 1);
	img->img_ptr = mlx_xpm_file_to_image(mlx, "assets/sl_road.xpm", &img->img_w, &img->img_h);
	img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->img_bpp, &img->img_size, &img->img_endian);

	// iteración anidada para cubrir al ventana con tiles
	int i = 0;
	while (i < 10)
	{
		int j = 0;
		while (j < 10)
			mlx_put_image_to_window(mlx, win, img->img_ptr, 32 * i, 32 * j++);
		i++;
	}

	// iteración anidada para dibujar lineas de 32 pixels de ancho
	i = 1;
	int ex = 0;
	int limit_h = 32 * 7;
	int limit_v = 32 * 3;
	while (ex < 32)
	{
		i = 1;
		while (i < limit_h)
			mlx_pixel_put(mlx, win, limit_v, i++, 0xFFFF00);
		i = 1;
		while (i < limit_v)
			mlx_pixel_put(mlx, win, ++i, limit_h, 0xFF00FF);
		limit_h++;
		limit_v++;
		ex++;
	}
	mlx_loop(mlx);
	//mlx_destroy(mlx);
}
