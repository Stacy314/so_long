################################################################################
#                                                                              #
#	                                Vars                                       #
#                                                                              #
################################################################################
CC          = cc
RM          = rm -rf
CFLAGS      = -Wall -Wextra -Werror -MD -MP -g -I $(INCLUDES) -I $(MLXDIR)

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

MLXDIR      = ./minilibx-linux
MLX         = -L$(MLXDIR) -lmlx -lXext -lX11 -lm

#MLX         = -lmlx -lX11 -lXext -lm 

SILENT = @

################################################################################
#                                                                              #
#	                                Rules                                      #
#                                                                              #
################################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLXDIR)/libmlx.a
	$(SILENT)$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) $(LIBFT) $(MLX)
	@echo "░██████╗░█████╗░░░░░░░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "██╔════╝██╔══██╗░░░░░░██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "╚█████╗░██║░░██║█████╗██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "░╚═══██╗██║░░██║╚════╝██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "██████╔╝╚█████╔╝░░░░░░███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "╚═════╝░░╚════╝░░░░░░░╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"
		
$(LIBFT):
	$(SILENT)$(MAKE) -C $(LIBDIR) all

$(MLXDIR)/libmlx.a:
	$(SILENT)$(MAKE) -C $(MLXDIR)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	$(SILENT)@mkdir -p $(OBJSDIR)
	$(SILENT)$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
		$(SILENT)$(MAKE) -s -C $(LIBDIR) clean
		$(SILENT)$(MAKE) -s -C $(MLXDIR) clean
		$(SILENT)$(RM) $(OBJSDIR)

fclean: clean
		$(SILENT)$(MAKE) -s -C $(LIBDIR) clean
		$(SILENT)$(MAKE) -s -C $(MLXDIR) clean
		$(SILENT)$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
