/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:19:51 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/27 11:48:48 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// static int  sl_handle_no_event(void *data);
static int	sl_handle_release(int keysym, t_game *g);
static int	sl_handle_press(int keysym, t_game *g);
static int	sl_handle_end(int keysym, t_game *g);
void		sl_game_end(t_game *g);

void	sl_run_game(t_game *g)
{
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &sl_handle_release, g);
	mlx_hook(g->win, 17, 0, &sl_handle_end, g);
	mlx_hook(g->win, KeyPress, KeyPressMask, &sl_handle_press, g);
	mlx_loop(g->mlx);
}	

static int	sl_handle_release(int keysym, t_game *g)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(g->mlx, g->win);
		g->win = NULL;
		mlx_loop_end(g->mlx);
		error_and_exit(FALSE, "", g);
	}
}

static int	sl_handle_press(int keysym, t_game *g)
{
	sl_find_pyr(g, &g->p_r, &g->p_c);
	if (keysym == XK_Up || keysym == XK_w)
		sl_move(-1, 0, g);
	if (keysym == XK_Down || keysym == XK_s)
		sl_move(1, 0, g);
	if (keysym == XK_Left || keysym == XK_a)
		sl_move(0, -1, g);
	if (keysym == XK_Right || keysym == XK_d)
		sl_move(0, 1, g);
}

static int	sl_handle_end(int keysym, t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	g->win = NULL;
	mlx_loop_end(g->mlx);
	error_and_exit(FALSE, "", g);
}

void	sl_game_end(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	g->win = NULL;
	mlx_loop_end(g->mlx);
	error_and_exit(FALSE, "", g);
}
