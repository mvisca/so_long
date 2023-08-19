#include "include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "HOLA");
	int i = 1;
	while (i < 100)
	{
		mlx_pixel_put(mlx, win, 100, i, 0xFFFF00);
		mlx_pixel_put(mlx, win, i++, 100, 0xFF00FF);
	}
	mlx_loop(mlx);
	//mlx_destroy(mlx);
}
