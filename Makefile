CC          = cc
RM          = rm -rf
CFLAGS      = -Wall -Wextra -Werror -MD -MP -g -I $(INCLUDES)

NAME        = so_long
SRCSDIR     = src
INCLUDES    = includes
SRCS        = $(SRCSDIR)/main.c $(SRCSDIR)/player.c $(SRCSDIR)/game.c $(SRCSDIR)/valid_map.c \
              $(SRCSDIR)/load_map.c $(SRCSDIR)/render.c $(SRCSDIR)/flood_fill.c $(SRCSDIR)/free.c \
			  $(SRCSDIR)/get_map_size.c

OBJSDIR     = obj
OBJS        = $(OBJSDIR)/main.o $(OBJSDIR)/player.o $(OBJSDIR)/game.o $(OBJSDIR)/valid_map.o \
              $(OBJSDIR)/load_map.o $(OBJSDIR)/render.o $(OBJSDIR)/flood_fill.o $(OBJSDIR)/free.o \
			  $(OBJSDIR)/get_map_size.o
DEPS        = $(OBJS:.o=.d)

LIBDIR      = ./libft
LIBFT       = $(LIBDIR)/libft.a

MLX         = -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) $(LIBFT) $(MLX)
		
$(LIBFT):
		$(MAKE) -C $(LIBDIR) all


$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
		$(MAKE) -C $(LIBDIR) clean
		$(RM) $(OBJSDIR)

fclean: clean
		$(MAKE) -C $(LIBDIR) fclean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
