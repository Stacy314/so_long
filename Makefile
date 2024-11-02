CC          = cc
RM          = rm -rf
CFLAGS      = -Wall -Wextra -Werror -MD -MP -g -I $(INCLUDES)

NAME        = so_long
SRCSDIR     = src
INCLUDES    = includes
SRCS        = $(SRCSDIR)/main.c $(SRCSDIR)/player.c $(SRCSDIR)/game.c $(SRCSDIR)/map.c \
              $(SRCSDIR)/map2.c $(SRCSDIR)/render.c $(SRCSDIR)/flood_fill.c

OBJSDIR     = obj
OBJS        = $(OBJSDIR)/main.o $(OBJSDIR)/player.o $(OBJSDIR)/game.o $(OBJSDIR)/map.o \
              $(OBJSDIR)/map2.o $(OBJSDIR)/render.o $(OBJSDIR)/flood_fill.o
DEPS        = $(OBJS:.o=.d)

LIBDIR      = ./libft
LIBFT       = $(LIBDIR)/libft.a

MLXDIR      = ./minilibx-linux
MLX         = -L$(MLXDIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLXDIR)/libmlx.a
		$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) $(LIBFT) $(MLX)
		
$(LIBFT):
		$(MAKE) -C $(LIBDIR) all

$(MLXDIR)/libmlx.a:
		$(MAKE) -C $(MLXDIR)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
		$(MAKE) -C $(LIBDIR) clean
		$(MAKE) -C $(MLXDIR) clean
		$(RM) $(OBJSDIR)

fclean: clean
		$(MAKE) -C $(LIBDIR) fclean
		$(MAKE) -C $(MLXDIR) clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re