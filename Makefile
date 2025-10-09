NAME = fractol
SOURCES = c_str_d.c julia.c main.c mandelbrot.c utils.c utils2.c
OBJECTS = $(SOURCES:.c=.o)

MLX_PATH = /home/yel-joul/minilibx-linux
MLX_INC = -I$(MLX_PATH)
MLX_LIB = $(MLX_PATH)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(LIBS) -o $(NAME)

%.o: %.c h_mlx.h
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.SECONDARY: $(OBJECTS)
.PHONY: all clean fclean re
