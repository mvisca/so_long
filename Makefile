#---------- TARGET ---------------------#

NAME	:=	so_long

#---------- INGREDIENTS -----------------#

SRC		:=	src/so_long.c

#---------- INGREDIENTS -----------------#

CC		:=	cc

#---------- OS SPECIFIC FLAGS ----------#

ifeq ($(shell uname -s),Darwin)  # macOS
	OSFLAGS := -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit
else ifeq ($(shell uname -s),Linux)  # Linux
	OSFLAGS := -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz
else
	$(error Sistema operativo no compatible)
endif

all: $(NAME)
	$(CC) $(SRC) $(OSFLAGS) -o $<

test:
	$(CC) src/lib_test.c $(OSFLAGS) -o test

.PHONY: test