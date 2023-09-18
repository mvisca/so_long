/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:08:09 by mvisca            #+#    #+#             */
/*   Updated: 2023/09/14 11:10:18 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Librerías requeridas
# include <unistd.h>    // open(), read(), write(), close()
# include <stdlib.h>    // malloc(), free(), exit()
# include <stdio.h>     // perror()
# include <string.h>    // strerror()
# include <fcntl.h>     // O_RDONLY
# include "sl_types.h"
# include "sl_defines.h"
# include "../libs/libft/include/libft.h"

// Selecciona el header de minilib para MacOS o Linux
# include "../libs/minilibx/mlx.h"

// sl_init.c
void	sl_init(char *filename, t_game *g);

// sl_map_init.c
t_map	*sl_map_init(char *filename, t_game *g);
char	**sl_load_map(char *filename, t_game *g);
int		sl_get_map_xy(char *info, int option, t_game *g);

// sl_map_validate.c
t_map	*sl_map_validate(t_game *g);

// sl_map_validate_solve.c
void	sl_find_pyr(t_game *g, int *pr, int *pc);

// sl_map_show.c
void	sl_map_show(t_game *g);

// sl_map_validate.c
int		sl_solvable(t_game *g);

// sl_game_run.c
void	sl_run_game(t_game *g);

// sl_game_run.c
void	sl_move(int r_move, int c_move, t_game *g);
void	sl_game_end(t_game *g);

// sl_utils.c
void	error_and_exit(int msj, char *str, t_game *g);
void	free_map(t_game *g);
void	free_img(t_game *g);
void	sl_freemap(t_game *g, t_map **map);

#endif
