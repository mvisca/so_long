/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:36:16 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/26 13:29:22 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sl_putimg(void *mlx, void *win, void *ptr, int r, int c);

void sl_map_show(t_game *g)
{
	int r;
	int c;

	r = 0;
	while (r < g->map->r)
	{
		c = 0;
		while (c < g->map->c)
		{
			if (g->map->tiles[r][c] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->img[road]->ptr, c * 32, r * 32);
			else if (g->map->tiles[r][c] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->img[wall]->ptr, c * 32, r * 32);
			else if (g->map->tiles[r][c] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img[coll]->ptr, c * 32, r * 32);
    		else if (g->map->tiles[r][c] == 'B')
                mlx_put_image_to_window(g->mlx, g->win, g->img[pyr]->ptr, c * 32, r * 32);
    		else if (g->map->tiles[r][c] == 'E')
                mlx_put_image_to_window(g->mlx, g->win, g->img[goal]->ptr, c * 32, r * 32);
    		else if (g->map->tiles[r][c] == 'P')
                mlx_put_image_to_window(g->mlx, g->win, g->img[pyr]->ptr, c * 32, r * 32);
			c++;
		}
		r++;
	}    
}

static void	sl_putimg(void *mlx, void *win, void *ptr, int c, int r)
{
	mlx_put_image_to_window(mlx, win, ptr, c, r);
}

