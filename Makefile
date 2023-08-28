# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 12:07:44 by mvisca            #+#    #+#              #
#    Updated: 2023/08/28 17:29:55 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# // cc main.c -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit

# // cc main.c -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz -o prog

#---------- TARGET ---------------------#

NAME	:=	so_long

#---------- INGREDIENTS -----------------#

SRC		:=	src/so_long.c \
			src/sl_init.c \
			src/sl_utils.c \
			src/sl_map_init.c \
			src/sl_map_show.c \
			src/sl_map_validate.c \
			src/sl_map_validate_solve.c \
			src/sl_game_move.c \
			src/sl_game_run.c

LIBFT	:=	libft

DEBUG	:=	-g -fsanitize=address

#---------- INGREDIENTS -----------------#

CC		:=	cc

ifeq ($(shell uname -s),Darwin)  # macOS
	OSFLAGS := -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit
	OSMLX	:= mlx/minilibx
else ifeq ($(shell uname -s),Linux)  # Linux
	OSFLAGS := -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz
	OSMLX	:= mlx/minilibx-linux
else
	$(error Sistema operativo no compatible)
endif

LIBFTFLAGS	:=	-Llibft -lft -Ilibft/include

#---------- OS SPECIFIC FLAGS ----------#


all: callforlib $(NAME)

$(NAME): $(LIBFT) $(MLX)
	$(CC) $(SRC) $(OSFLAGS) $(LIBFTFLAGS) $(DEBUG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C libft/ --silent

$(MLX):
	@$(MAKE) -C $(OSMLX) --silent

callforlib:
	@$(MAKE) -C libft/ --silent
	@$(MAKE) -C $(OSMLX) --silent


fclean:
	rm -rf so_long test
	@$(MAKE) -C libft/ fclean --silent
	@$(MAKE) -C $(OSMLX) clean --silent

re: fclean all

test:
	$(CC) src/lib_test.c $(OSFLAGS) $(DEBUG) -o test

.PHONY: fclean re test