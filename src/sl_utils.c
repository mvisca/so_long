/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:52:40 by mvisca            #+#    #+#             */
/*   Updated: 2023/09/14 12:59:54 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_game *g);
void	free_img(t_game *g);
void	sl_freemap(t_game *g, t_map **map);

void	error_and_exit(int msj, char *str, t_game *g)
{
	if (msj)
		ft_printf("%s", str);
	if (g->img)
		free_img(g);
	if (g->win)
	{
		mlx_destroy_window(g->mlx, g->win);
		free(g->win);
	}
	if (g->mlx)
	{
		free(g->win);
		free(g->mlx);
	}
	if (g->map && g->map->tiles)
		free_map(g);
	if (g->map)
		free(g->map);
	if (msj)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	if (g->map->tiles[0] && g->map->tiles[0][0] != 0)
	{
		while (g->map && g->map->tiles && g->map->tiles[i])
		{
			free(g->map->tiles[i]);
			i++;
		}
	}
	free(g->map->tiles);
}

void	free_img(t_game *g)
{
	if (g->img && g->img[road])
	{
		mlx_destroy_image(g->mlx, g->img[road]->ptr);
		g->img[road]->ptr = NULL;
		free(g->img[road]);
		mlx_destroy_image(g->mlx, g->img[wall]->ptr);
		g->img[wall]->ptr = NULL;
		free(g->img[wall]);
		mlx_destroy_image(g->mlx, g->img[coll]->ptr);
		g->img[coll]->ptr = NULL;
		free(g->img[coll]);
		mlx_destroy_image(g->mlx, g->img[goal]->ptr);
		g->img[goal]->ptr = NULL;
		free(g->img[goal]);
		mlx_destroy_image(g->mlx, g->img[pyr]->ptr);
		g->img[pyr]->ptr = NULL;
		free(g->img[pyr]);
		free(g->img);
		g->img = NULL;
	}
}

void	sl_freemap(t_game *g, t_map **map)
{
	int	r;

	r = 0;
	while (r < g->map->r)
		free((*map)->tiles[r++]);
	free((*map)->tiles);
	free(*map);
}
