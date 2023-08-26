/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:39:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/26 17:23:22 by mvisca           ###   ########.fr       */
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
	int			pyr;
	int			coll;
	int			goal;
}	t_map;

typedef struct s_slimg
{
	void		*ptr;
	int			*data;
	int			size;
	int			bpp;
	int			endian;
	int			w;
	int			h;
}	t_slimg;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_slimg		**img;
	int			img_w; // for test
	int			img_h; // for test
	int			turns;
}	t_game;

#endif
