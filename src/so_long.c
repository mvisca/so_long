/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:37:00 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 14:48:53 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	g;

	g.mlx = mlx_init();
	if (ac == 2)
	{
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
	mlx_loop(g.mlx);
	error_and_exit(FALSE, "", &g);
}
