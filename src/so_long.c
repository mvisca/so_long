/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:37:00 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/26 14:21:18 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sl_g_null(t_game *g);

int	main(int ac, char **av)
{
	t_game	g;
	char	*filename;

	sl_g_null(&g);
	if (ac == 2)
	{
		filename = av[1];
		sl_init(av[1], &g);
		sl_map_show(&g);
		sl_run_game(&g);
		// binding de teclas
		// control del juego
		
	// images test
		// mlx_put_image_to_window(g.mlx, g.win, g.img[goal]->ptr, 0 * 32, 1 * 32);
//		mlx_hook(g->win, 2, 0, sl_game_read_keys, g);
//		mlx_hook(g->win, 17, 0, sl_game_destroy, g);
	}
	mlx_loop(g.mlx);
	error_and_exit(FALSE, "", &g);
}

static void	sl_g_null(t_game *g)
{
	g->mlx = NULL;	
	g->win = NULL;
	g->map = NULL;
	g->img = NULL;
}
