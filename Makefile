
#---------- TARGET ---------------------#

NAME	:=	so_long

#---------- OS SPECIFIC FLAGS ----------#

ifeq ($(shell uname -s),Darwin)  # macOS
    OSFLAGS := -Lmlx/minilibx -lmlx -Imlx/minilibx -framework OpenGl -framework AppKit
else ifeq ($(shell uname -s),Linux)  # Linux
    OSFLAGS := -Lmlx/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx/minilibx-linux -lXext -lX11 -lm -lz
else
    $(error Sistema operativo no compatible)
endif

all:
	cc main.c $(OSFLAGS) -o prog

test:
	printf "$(OSFLAGS)"
