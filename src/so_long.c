/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:37:00 by mvisca            #+#    #+#             */
/*   Updated: 2023/09/14 11:08:20 by mvisca-g         ###   ########.fr       */
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
		sl_init(filename, &g);
		sl_map_show(&g);
		sl_run_game(&g);
	}
	error_and_exit(FALSE, "", &g);
}

static void	sl_g_null(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->map = NULL;
	g->img = NULL;
}
