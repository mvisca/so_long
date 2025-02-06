/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:19:51 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/13 13:27:23 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	sl_handle_arrows(int keysym, t_game *g);
void		sl_game_end(t_game *g);

void	sl_run_game(t_game *g)
{
	mlx_hook(g->win, 17, 0, (void *) sl_game_end, g);
	mlx_hook(g->win, 2, 1L << 0, sl_handle_arrows, g);
	write(1, "in loop\n", 8);
	mlx_loop(g->mlx);
	write(1, "out loop\n", 9);
}

static int	sl_handle_arrows(int keysym, t_game *g)
{
	sl_find_pyr(g, &g->p_r, &g->p_c);
	if (keysym == ARRU || keysym == W)
		sl_move(-1, 0, g);
	else if (keysym == ARRD || keysym == S)
		sl_move(1, 0, g);
	else if (keysym == ARRL || keysym == A)
		sl_move(0, -1, g);
	else if (keysym == ARRR || keysym == D)
		sl_move(0, 1, g);
	else if (keysym == ESC)
		sl_game_end(g);
	return (FALSE);
}

void	sl_game_end(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	g->win = NULL;
	error_and_exit(FALSE, "", g);
}
