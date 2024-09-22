NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a

SRC = src/main.c src/map.c src/events.c src/render.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
