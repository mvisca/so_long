/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:52:40 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 14:02:49 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map);
void	free_img(t_img **img);

void    error_and_exit(int msj, char *str, t_game *g)
{
	int i;
	if (msj)
		ft_printf("%s", str);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		free(g->mlx);
	if (g->map)
		free_map(g->map);
	if (g->img)
	{
		free_img(g->img);
		g->img = NULL;
	}
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->tiles && map->tiles[i])
	{
		free(map->tiles[i]);
		i++;
	}
	free(map->tiles);
	free(map);
}

void	free_img(t_img **img)
{
	free(img[road]);
	img[road] = NULL;
	free(img[wall]);
	img[wall] = NULL;
	free(img[coll]);
	img[coll] = NULL;
	free(img[goal]);
	img[goal] = NULL;
	free(img[player]);
	img[player] = NULL;
}
