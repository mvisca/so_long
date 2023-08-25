#include "../include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_slimg	*img1;
	t_slimg	*img2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 320, 320, "HOLA");

	// crea struct con los datos para mostrar imagen
	img1 = (t_slimg *) malloc (sizeof(t_slimg) * 1);
	img1->ptr = mlx_xpm_file_to_image(mlx, "a/r.xpm", &img1->w, &img1->h);
	img1->data = (int *)mlx_get_data_addr(img1->ptr, &img1->bpp, &img1->size, &img1->endian);

	img2 = (t_slimg *) malloc (sizeof(t_slimg) * 1);
	img2->ptr = mlx_xpm_file_to_image(mlx, "a/g.xpm", &img2->w, &img2->w);
	img2->data = (int *)mlx_get_data_addr(img2->ptr, &img2->bpp, &img2->size, &img2->endian);

	// iteración anidada para cubrir al ventana con tiles
	int i = 0;
	while (i < 10)
	{
		int j = 0;
		while (j < 10)
			mlx_put_image_to_window(mlx, win, img1->ptr, 32 * i, 32 * j++);
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

	mlx_put_image_to_window(mlx, win, img2->ptr, 32 * 7, 32 * 7);

	mlx_loop(mlx);
	//mlx_destroy(mlx);
}
