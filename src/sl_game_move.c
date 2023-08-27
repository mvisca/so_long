/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:52:09 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/27 09:40:00 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    sl_move(int r_ini, int c_ini, int r_move, int c_move, t_game *g)
{
	char    ori;
	char    dest;

	ori = g->map->tiles[r_ini][c_ini];
	dest = g->map->tiles[r_ini + r_move][c_ini + c_move];
	if (dest == '1')
		return;
	if (ori == 'P')
		g->map->tiles[r_ini][c_ini] = '0';
	else if (ori == 'B')
		g->map->tiles[r_ini][c_ini] = 'E';
	if (dest == '0')
		g->map->tiles[r_ini + r_move][c_ini + c_move] = 'P';
	else if (dest == 'C')
	{
		g->map->tiles[r_ini + r_move][c_ini + c_move] = 'P';
		g->map->coll--;
	}
	else if (dest == 'E' && g->map->coll > 0)
		g->map->tiles[r_ini + r_move][c_ini + c_move] = 'B';
	else if (dest == 'E' && g->map->coll == 0)
		sl_game_end(g);
	ft_printf("Moves made: %d\n", ++(g->turns));
	sl_map_show(g);
}
