/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:52:09 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/27 11:35:00 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sl_congratulations(t_game *g);

void	sl_move(int r_move, int c_move, t_game *g)
{
	char	dest;

	dest = g->map->tiles[g->p_r + r_move][g->p_c + c_move];
	if (dest == '1')
		return ;
	if (g->map->tiles[g->p_r][g->p_c] == 'P')
		g->map->tiles[g->p_r][g->p_c] = '0';
	else if (g->map->tiles[g->p_r][g->p_c] == 'B')
		g->map->tiles[g->p_r][g->p_c] = 'E';
	if (dest == '0')
		g->map->tiles[g->p_r + r_move][g->p_c + c_move] = 'P';
	else if (dest == 'C')
		g->map->tiles[g->p_r + r_move][g->p_c + c_move] = 'P' \
		+ g->map->coll - g->map->coll--;
	else if (dest == 'E' && g->map->coll > 0)
		g->map->tiles[g->p_r + r_move][g->p_c + c_move] = 'B';
	else if (dest == 'E' && g->map->coll == 0)
		sl_congratulations(g);
	ft_printf("Moves made: %d\n", ++(g->turns));
	sl_map_show(g);
}

static void	sl_congratulations(t_game *g)
{
	ft_printf("Congratulations!\nGame complete in %d moves!", g->turns);
	sl_game_end(g);
}
