/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:08:53 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/27 11:54:42 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		sl_load_assets(t_game *g);
static void	*sl_xpmtoi(void *mlx, char *file, int *w, int *h);
static int	sl_valid_filename(char *filename);

void	sl_init(char *filename, t_game *g)
{
	if (!sl_valid_filename(filename))
		error_and_exit(TRUE, "Filename error\n", g);
	g->mlx = mlx_init();
	if (!g->mlx)
		error_and_exit(TRUE, "Display error\n", g);
	g->map = sl_map_init(filename, g);
	if (!g->map)
		error_and_exit(TRUE, "Map error\n", g);
	g->win = mlx_new_window(g->mlx, g->map->c * 32, g->map->r * 32, "So Long");
	if (!g->win)
		error_and_exit(TRUE, "Window error\n", g);
	sl_load_assets(g);
	g->turns = 0;
}

void	sl_load_assets(t_game *g)
{
	int	i;

	g->img = (t_slimg **) malloc (sizeof(t_slimg *) * 5);
	i = 0;
	if (!g->img)
		error_and_exit(TRUE, "Images error\n", g);
	while (i < 5)
	{
		g->img[i] = (t_slimg *) malloc (sizeof(t_slimg));
		if (!g->img[i])
			error_and_exit(TRUE, "Images error\n", g);
		i++;
	}
	g->img[road]->ptr = sl_xpmtoi(g->mlx, "img/r.xpm", &g->img_w, &g->img_h);
	g->img[wall]->ptr = sl_xpmtoi(g->mlx, "img/w.xpm", &g->img_w, &g->img_h);
	g->img[coll]->ptr = sl_xpmtoi(g->mlx, "img/c.xpm", &g->img_w, &g->img_h);
	g->img[goal]->ptr = sl_xpmtoi(g->mlx, "img/g.xpm", &g->img_w, &g->img_h);
	g->img[pyr]->ptr = sl_xpmtoi(g->mlx, "img/p.xpm", &g->img_w, &g->img_h);
}

void	*sl_xpmtoi(void *mlx, char *file, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, file, w, h);
	return (img);
}

int	sl_valid_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (FALSE);
	if (ft_tolower(filename[len - 1]) != 'r')
		return (FALSE);
	if (ft_tolower(filename[len - 2]) != 'e')
		return (FALSE);
	if (ft_tolower(filename[len - 3]) != 'b')
		return (FALSE);
	if (ft_tolower(filename[len - 4]) != '.')
		return (FALSE);
	return (TRUE);
}
