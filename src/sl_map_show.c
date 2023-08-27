/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:36:16 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/27 12:05:41 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sl_putimg(t_game *g, int r, int c, t_tiles type);

void	sl_map_show(t_game *g)
{
	int	r;
	int	c;

	r = 0;
	while (r < g->map->r)
	{
		c = 0;
		while (c < g->map->c)
		{
			if (g->map->tiles[r][c] == '0')
				sl_putimg(g, c, r, road);
			else if (g->map->tiles[r][c] == '1')
				sl_putimg(g, c, r, wall);
			else if (g->map->tiles[r][c] == 'C')
				sl_putimg(g, c, r, coll);
			else if (g->map->tiles[r][c] == 'B')
				sl_putimg(g, c, r, pyr);
			else if (g->map->tiles[r][c] == 'E')
				sl_putimg(g, c, r, goal);
			else if (g->map->tiles[r][c] == 'P')
				sl_putimg(g, c, r, pyr);
			c++;
		}
		r++;
	}
}

static void	sl_putimg(t_game *g, int c, int r, t_tiles type)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img[type]->ptr, c * 32, r * 32);
}
