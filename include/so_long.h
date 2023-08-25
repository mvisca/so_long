#ifndef SO_LONG_H
# define SO_LONG_H

// Librerías requeridas
# include <unistd.h>    // open(), read(), write(), close()
# include <stdlib.h>    // malloc(), free(), exit()
# include <stdio.h>     // perror()
# include <string.h>    // strerror()
# include <fcntl.h>     // O_RDONLY
# include "sl_types.h"
# include "../libft/include/libft.h"

// Selecciona el header de minilib para MacOS o Linux
# ifdef __APPLE__
#  include "../mlx/minilibx/mlx.h"
#  include "../mlx/minilibx/mlx_int.h"
# elif __linux__
#  include "../mlx/minilibx-linux/mlx.h"
#  include "../mlx/minilibx-linux/mlx_int.h"
# else
#  error "Sistema opeartivo no compatible"
# endif

// sl_init.c
void    sl_init(char *filename, t_game *g);
void	sl_load_assets(t_game *g);
void	*sl_xpmtoi(void *mlx, char *file, int *w, int* h);

// sl_map_init.c
t_map	*sl_map_init(char *filename, t_game *g);
char	**sl_load_map(char *filename, t_game *g);
int		sl_get_map_xy(char *info, int option, t_game *g);

// sl_map_validate.c
t_map	*sl_map_validate(t_game *g);

// sl_map_validate.c
int	sl_solvable(t_game *g);

// sl_utils.c
void    error_and_exit(int msj, char *str, t_game *g);
void	free_map(t_game *g);
void	free_img(t_game *g);

#endif

// cc main.c -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit

// cc main.c -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz -o prog
