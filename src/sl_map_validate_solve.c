/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_validate_solve.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:02:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/25 12:45:03 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sl_find_pyr(t_game *g, int *pr, int *pc);
static char	**sl_mapdup(t_game *g, t_map **map);
static void	sl_pathfinder(t_map **map, int pr, int pc);
static void	sl_freemap(t_game *g, t_map **map);

int	sl_solvable(t_game *g)
{
	int		pr;
	int		pc;
	int		r;
	t_map	*map;

	sl_find_pyr(g, &pr, &pc);
	map = (t_map *) malloc (sizeof(t_map));
	if (!map)
		error_and_exit(TRUE, "Map copy memory alloc error\n", g);
	map->tiles = sl_mapdup(g, &map);
	map->coll = 0;
	map->goal = 0;
	sl_pathfinder(&map, pr, pc);
	int i = 0;
	while (i < g->map->r)
	{
		ft_printf("%s\n", map->tiles[i++]);
	}
	ft_printf("coll = %d, goal = %d\n", map->coll, map->goal);
	if (map->coll != g->map->coll || map->goal != g->map->goal)
	{
		sl_freemap(g, &map);
		return (FALSE);
	}
	sl_freemap(g, &map);
	return (TRUE);
}

static void	sl_freemap(t_game *g, t_map **map)
{
	int	r;
	
	r = 0;
	while (r < g->map->r)
		free((*map)->tiles[r++]);
	free((*map)->tiles);
	free(*map);
}

static char	**sl_mapdup(t_game *g, t_map **map)
{
	int	r;
	
	(*map)->tiles = (char **) malloc (sizeof(char *) * g->map->r);
	if (!(*map)->tiles)
		error_and_exit(TRUE, "Map copy memory alloc error\n", g);
	r = 0;
	while (r < g->map->r)
	{
		(*map)->tiles[r] = ft_strdup(g->map->tiles[r]);
		if (!(*map)->tiles[r])
		{
			while (r > 0)
				free((*map)->tiles[--r]);
			free((*map)->tiles);
			free(*map);
			error_and_exit(TRUE, "Map copy memory alloc error\n", g);
		}
		r++;
	}
	return ((*map)->tiles);
}


static void    sl_find_pyr(t_game *g, int *pr, int *pc)
{
	int 	r;
	int 	c;

	r = 1;
	while (r < g->map->r - 1)
	{
		c = 1;
		while (c < g->map->c - 1)
		{
			if (g->map->tiles[r][c] == 'P')
			{
				*pr = r;
				*pc = c;
				return ;
			}
			c++;
		}
		r++;
	}
	error_and_exit(TRUE, "Map no player error\n", g);
}

static void	sl_pathfinder(t_map **map, int pr, int pc)
{
	if ((*map)->tiles[pr][pc] == 'C')
		(*map)->coll++;
	else if ((*map)->tiles[pr][pc] == 'E')
		(*map)->goal++;
	(*map)->tiles[pr][pc] = 'X';
	if ((pr - 1 > 0) && (!ft_strchr("X1", (*map)->tiles[pr - 1][pc])))
		sl_pathfinder(map, pr - 1, pc);
	if ((pr + 1 < (*map)->r - 1) && (!ft_strchr("X1", (*map)->tiles[pr + 1][pc])))
		sl_pathfinder(map, pr + 1, pc);
	if ((pc - 1 > 0) && (!ft_strchr("X1", (*map)->tiles[pr][pc - 1])))
		sl_pathfinder(map, pr, pc - 1);
	if ((pc + 1 < (*map)->c - 1) && (!ft_strchr("X1", (*map)->tiles[pr][pc + 1])))
		sl_pathfinder(map, pr, pc + 1);
}
// este algoritmo está mal
// debe recorrer todo el mapa para no lo está haciendo
// duplico el mapa ok
// libero el mapa ok