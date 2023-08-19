#include "include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 10 * 32, 10 * 32, "HOLA");
	mlx_loop(mlx);
	mlx_loop(mlx);
	//mlx_destroy(mlx);
}
