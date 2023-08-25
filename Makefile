#---------- TARGET ---------------------#

NAME	:=	so_long

#---------- INGREDIENTS -----------------#

SRC		:=	src/so_long.c \
			src/sl_init.c \
			src/sl_utils.c \
			src/sl_map_init.c \
			src/sl_map_validate.c \
			src/sl_map_validate_solve.c

LIBFT	:=	libft

DEBUG	:=	-g -fsanitize=address

#---------- INGREDIENTS -----------------#

CC		:=	cc

ifeq ($(shell uname -s),Darwin)  # macOS
	OSFLAGS := -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit
else ifeq ($(shell uname -s),Linux)  # Linux
	OSFLAGS := -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz
else
	$(error Sistema operativo no compatible)
endif

LIBFTFLAGS	:=	-Llibft -lft -Ilibft/include

#---------- OS SPECIFIC FLAGS ----------#


all: callforlib $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(SRC) $(OSFLAGS) $(LIBFTFLAGS) $(DEBUG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C libft/ --silent

callforlib:
	@$(MAKE) -C libft/ --silent

fclean:
	rm -rf so_long test
	@$(MAKE) -C libft/ fclean --silent

re: fclean all

test:
	$(CC) src/lib_test.c $(OSFLAGS) $(DEBUG) -o test

.PHONY: fclean re test