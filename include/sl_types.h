/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:39:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/23 13:06:55 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_TYPES_H
# define SL_TYPES_H

# define BLOCK_SIZE 32

typedef enum e_cell_def
{
	road,
	wall,
	collectible,
	exit,
	p_still,
	p_up,
	p_down,
	p_left,
	p_right
}   t_cell;

typedef struct s_map
{
	t_cell		**e_cell;
	int			width;
	int			height;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			img_data;
	int			img_size;
	int			img_bpp;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*map;
	t_img		*img;
	int			turns;
}	t_game;

#endif
