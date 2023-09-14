/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:10:23 by mvisca            #+#    #+#             */
/*   Updated: 2023/09/14 12:01:43 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	sl_same_len_cols(t_game *g);
static int	sl_map_wall_borders(t_game *g);
static int	sl_proper_elements(t_game *g);

t_map	*sl_map_validate(t_game *g)
{
	if (g->map->c == g->map->r || !sl_same_len_cols(g))
		error_and_exit(TRUE, "Map dimensions error\n", g);
	if (!g->map->tiles[0][0])
		error_and_exit(TRUE, "Empty file\n", g);
	if (!sl_map_wall_borders(g))
		error_and_exit(TRUE, "Map borders error\n", g);
	if (!sl_proper_elements(g))
		error_and_exit(TRUE, "Map elements error\n", g);
	if (g->map->goal != 1 || g->map->pyr != 1 || g->map->coll == 0)
		error_and_exit(TRUE, "Map player/exit/coll error\n", g);
	if (!sl_solvable(g))
		error_and_exit(TRUE, "Map not possible error\n", g);
	return (g->map);
}

static int	sl_same_len_cols(t_game *g)
{
	int	r;
	int	len;

	r = 0;
	len = ft_strlen(g->map->tiles[0]);
	while (r < g->map->r)
	{
		if (len != (int)ft_strlen(g->map->tiles[r]))
			return (FALSE);
		r++;
	}
	return (TRUE);
}

static int	sl_map_wall_borders(t_game *g)
{
	int	lst_r;
	int	lst_c;
	int	i;

	lst_r = g->map->r;
	lst_c = g->map->c;
	i = 0;
	while (i < lst_c)
	{
		if (g->map->tiles[0][i] != '1')
			return (FALSE);
		if (g->map->tiles[lst_r - 1][i] != '1')
			return (FALSE);
		i++;
	}
	while (i < lst_r)
	{
		if (g->map->tiles[i][0] != '1')
			return (FALSE);
		if (g->map->tiles[i][lst_c - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	sl_proper_elements(t_game *g)
{
	int	r;
	int	c;

	g->map->pyr = 0;
	g->map->coll = 0;
	g->map->goal = 0;
	r = 0;
	while (g->map && g->map->tiles && g->map->tiles[r])
	{
		c = 0;
		while (g->map->tiles[r][c])
		{
			if (!ft_strchr("01CEP", g->map->tiles[r][c]))
				return (FALSE);
			else if (g->map->tiles[r][c] == 'C')
				g->map->coll++;
			else if (g->map->tiles[r][c] == 'E')
				g->map->goal++;
			else if (g->map->tiles[r][c] == 'P')
				g->map->pyr++;
			c++;
		}
		r++;
	}
	return (TRUE);
}
