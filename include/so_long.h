#ifndef SO_LONG_H
# define SO_LONG_H

// Librerías requeridas
# include <unistd.h>    // open(), read(), write(), close()
# include <stdlib.h>    // malloc(), free(), exit()
# include <stdio.h>     // perror()
# include <string.h>    // strerror()

// Selecciona el header para MacOS o Linux
# ifdef __APPLE__
#  include "../mlx/minilibx/mlx.h"
# elif __linux__
#  include "../mlx/minilibx-linux/mlx.h"
# else
#  error "Sistema opeartivo no compatible"
# endif

# include "sl_types.h" // Tipos de datos customizados
# include "../libft/include/libft.h" // Libft functions & ft_printf

#endif

// cc main.c -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit

// cc main.c -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz -o prog
