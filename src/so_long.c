/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:37:00 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 14:04:37 by mvisca           ###   ########.fr       */
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
		ft_printf("rows = %d\n", g.map->rows);
		ft_printf("cols = %d\n", g.map->cols);
		while (i < g.map->rows)
		{
			ft_printf("main: %s\n", g.map->tiles[i]);
			i++;
		}
		mlx_loop(g.mlx);
		ft_printf("ok!\n");
	}
	error_and_exit(FALSE, "", &g);
}
