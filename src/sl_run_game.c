/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:19:51 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/26 17:24:27 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <X11/keysym.h>

static int  sl_handle_no_event(void *data);
static int  sl_handle_release(int keysym, t_game *g);
static int  sl_handle_press(int keysym, t_game *g);

void    sl_run_game(t_game *g)
{
	mlx_loop_hook(g->mlx, &sl_handle_no_event, g);
	// mlx_hook(g->mlx, KeyPress, KeyPressMask, &sl_handle_press, g);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &sl_handle_release, g);
	mlx_hook(g->win, KeyPress, KeyPressMask, &sl_handle_press, g);
	mlx_loop(g->mlx);
}	

static int  sl_handle_no_event(void *data)
{
	return (0);
}

static int  sl_handle_release(int keysym, t_game *g)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(g->mlx, g->win);
		g->win = NULL;
	}
}

static int  sl_handle_press(int keysym, t_game *g)
{
	if (keysym == XK_Up || keysym == XK_w)
		ft_printf("UP\n");
	if (keysym == XK_Down || keysym == XK_s)
		ft_printf("DW\n");
	if (keysym == XK_Left || keysym == XK_a)
		ft_printf("LF\n");
	if (keysym == XK_Right || keysym == XK_d)
		ft_printf("RI\n");
}

/*
# define ESC	53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125
# define A 0
# define W 13
# define S 1
# define D 2
*/