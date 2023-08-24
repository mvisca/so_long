/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:52:40 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 15:20:57 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_game *g);
void	free_img(t_game *g);

void    error_and_exit(int msj, char *str, t_game *g)
{
	int i;
	if (msj)
		ft_printf("%s", str);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		free(g->mlx);
	if (g->map->tiles)
		free_map(g);
	if (g->map)
		free(g->map);
	if (g->img)
		free_img(g);
	if (msj)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	while (g->map && g->map->tiles && g->map->tiles[i])
	{
		free(g->map->tiles[i]);
		i++;
	}
	free(g->map->tiles);
}

void	free_img(t_game *g)
{
	if (g->img)
	{
		free(g->img[road]);
		g->img[road] = NULL;
		free(g->img[wall]);
		g->img[wall] = NULL;
		free(g->img[coll]);
		g->img[coll] = NULL;
		free(g->img[goal]);
		g->img[goal] = NULL;
		free(g->img[pyr]);
		g->img[pyr] = NULL;
		free(g->img);
		g->img = NULL;
	}
}
