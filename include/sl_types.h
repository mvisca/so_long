/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:39:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/24 14:37:09 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_TYPES_H
# define SL_TYPES_H

# define BLOCK_SIZE 32
# define TRUE 1
# define FALSE 0

typedef enum e_tiles
{
	road,
	wall,
	coll,
	goal,
	pyr
}   t_tiles;

typedef struct s_map
{
	char		**tiles;
	int			r;
	int			c;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			*img_data;
	int			img_size;
	int			img_bpp;
	int			img_endian;
	int			w;
	int			h;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_img		**img;
	int			img_w; // for test
	int			img_h; // for test
	int			turns;
}	t_game;

#endif
