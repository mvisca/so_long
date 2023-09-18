# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 12:07:44 by mvisca            #+#    #+#              #
#    Updated: 2023/09/14 12:58:26 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# // cc main.c -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit

# // cc main.c -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz -o prog

#---------- FORMAT ----------------------#

RED			:= \033[0;31m
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
BLUE		:= \033[0;34m
NC			:= \033[0m

#---------- TARGET ----------------------#

NAME		:=	so_long

#---------- FILES & DIRS ----------------#

SRC			:= src/so_long.c \
			   src/sl_init.c \
			   src/sl_utils.c \
			   src/sl_map_init.c \
			   src/sl_map_show.c \
			   src/sl_map_validate.c \
			   src/sl_map_validate_solve.c \
			   src/sl_game_move.c \
			   src/sl_game_run.c

OBJ			:= $(addprefix .build/, $(notdir $(SRC:.c=.o)))

DEP			:= $(OBJ:.o=.d)

HEADERS		:= include/sl_defines.h \
			   include/sl_types.h \
			   include/so_long.h

LFTDIR		:= libs/libft/
MLXDIR		:= libs/minilibx/

#---------- LIBS ------------------------#

LIBFT		:= $(LFTDIR)libft.a
MLX			:= $(MLXDIR)libmlx.a

#---------- INGREDIENTS ---------------------#

CC			:= cc -Wall -Wextra -Werror

DEBUG		:= -g -fsanitize=address

MLXFLAGS 	:= -L$(MLXDIR) -lmlx -I$(MLXDIR)include -framework OpenGl -framework AppKit

LFTFLAGS	:= -L$(LFTDIR) -lft -I$(LFTDIR)include

#---------- RECIPES ---------------------#

all: mlx libft $(NAME) | callforlib

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(SRC) $(MLXFLAGS) $(LFTFLAGS) -o $(NAME)
	@echo "$(YELLOW)Packing $(RED)$(NAME) $(YELLOW)ready!$(NC)"

mlx:
	@$(MAKE) -C $(MLXDIR) --silent
	
libft:
	@$(MAKE) -C $(LFTDIR) --silent

.build/%.o: src/%.c $(HEADERS) $(MLX) $(LIBFT) Makefile
	@mkdir -p .build
	@$(CC) $(DEBUG) -MMD $< -c -o $@
	@echo "$(GREEN)Creating... $(NC)$(notdir $<) $(RED)-> $(NC)$(notdir $@)"

-include $(DEP)

#---------- OTHERS -----------------------#

callforlib: mlx libft

show_obj:
	echo "$(OBJ)"

clean:
	@$(MAKE) -C $(MLXDIR) clean --silent
	@$(MAKE) -C $(LFTDIR) clean --silent
	@rm -rf .build

fclean: clean
	@rm -rf so_long
	@$(MAKE) -C $(LFTDIR) fclean --silent

re: fclean all

.PHONY: clean fclean re
