/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:37:00 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 15:47:40 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sl_g_null(t_game *g);

int	main(int ac, char **av)
{
	t_game	g;

	sl_g_null(&g);
	if (ac == 2)
	{
		g.mlx = mlx_init();
		sl_init(av[1], &g);

		int i = 0;
		ft_printf("rows = %d\n", g.map->r);
		ft_printf("cols = %d\n", g.map->c);
		while (i < g.map->r)
		{
			ft_printf("main: %s\n", g.map->tiles[i]);
			i++;
		}
		ft_printf("ok!\n");
	}
	// images test
	mlx_put_image_to_window(g.mlx, g.win, g.img[goal], 0 * 32, 1 * 32);
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
