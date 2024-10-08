CC          = cc
RM          = rm -rf
CFLAGS      = -Wall -Wextra -Werror -MD -MP -g -I $(INCLUDES)

NAME        = so_long
SRCSDIR     = src
INCLUDES    = includes
SRCS        = \
            main.c \
            events.c \
            game.c \
            map.c \
            render.c \
			flood_fill.c \

OBJSDIR     = objs
OBJS        = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DEPS        = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))


LIBDIR      = ./libft
LIBFT       = $(LIBDIR)/libft.a

MLXDIR      = ./minilibx-linux
MLX         = -L$(MLXDIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS) $(LIBFT) $(MLXDIR)/libmlx.a
		$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) $(LIBFT) $(MLX)

$(LIBFT):
		$(MAKE) -C $(LIBDIR) all

$(MLXDIR)/libmlx.a:
		$(MAKE) -C $(MLXDIR)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) -C $(LIBDIR) clean
		$(MAKE) -C $(MLXDIR) clean
		$(RM) $(OBJSDIR) $(OBJSDIR_B)

fclean: clean
		$(MAKE) -C $(LIBDIR) fclean
		$(MAKE) -C $(MLXDIR) clean
		$(RM) $(NAME) $(NAME_B)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re bonus
