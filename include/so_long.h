#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__
#  include "../mlx/minilibx/mlx.h"
# elif __linux__
#  include "../mlx/minilibx-linux/mlx.h"
# else
#  error "Sistema opeartivo no compatible"
# endif

# include <unistd.h>

#endif

// cc main.c -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit

// cc main.c -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz -o prog
