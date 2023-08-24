/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:08:53 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 14:48:37 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*sl_game_init(t_game *g);
void	sl_load_assets(t_game *g);
void	*sl_ftoi(void *mlx, char *file, int *w, int* h);

void    sl_init(char *filename, t_game *g)
{
	g->map = sl_map_init(filename, g);
	if (!g->map)
		error_and_exit(TRUE, "Error spliting map\n", g);
	g = sl_game_init(g);
}

t_game	*sl_game_init(t_game *g)
{
	g->mlx = mlx_init();
//	if (!g->mlx)
//		error_and_exit(TRUE, "Error connectig display\n", g);
	g->win = mlx_new_window(g->mlx, g->map->c *32, g->map->r *32, "So Long");
	if (!g->win)
		error_and_exit(TRUE, "Error creating window\n", g);
//	sl_load_assets(g);
	g->turns = 0;
}

void	sl_load_assets(t_game *g)
{
	int	i;

	g->img = (t_img **) malloc (sizeof(t_img *) * 5);
	i = 0;
	if (!g->img)
		error_and_exit(TRUE, "Error loading images\n", g);
	while (i < 5)
	{
		g->img[i] = (t_img *) malloc (sizeof(t_img));
		if (!g->img[i])
			error_and_exit(TRUE, "Error loading images\n", g);
		i++;
	}
	g->img[road] = sl_ftoi(g->mlx, "assets/r.xpm", &g->img_w, &g->img_h);
	g->img[wall] = sl_ftoi(g->mlx, "assets/w.xpm", &g->img_w, &g->img_h);
	g->img[coll] = sl_ftoi(g->mlx, "assets/c.xpm",&g->img_w, &g->img_h);
	g->img[goal] = sl_ftoi(g->mlx, "assets/g.xpm",&g->img_w, &g->img_h);
	g->img[pyr] = sl_ftoi(g->mlx, "assets/c.xpm", &g->img_w, &g->img_h);
}

void	*sl_ftoi(void *mlx, char *file, int *w, int* h)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, file, w, h);
	return (img); 
}
