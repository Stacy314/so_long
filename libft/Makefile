NAME = libft.a

SRC = ft_strlen.c ft_itoa.c ft_split.c ft_isalpha.c ft_strdup.c \
ft_striteri.c ft_bzero.c ft_strnstr.c ft_isalnum.c ft_substr.c \
ft_strlcpy.c ft_memchr.c ft_strmapi.c ft_calloc.c ft_toupper.c \
ft_strrchr.c ft_memcmp.c ft_strtrim.c ft_putnbr_fd.c ft_atoi.c \
ft_memcpy.c ft_tolower.c ft_split.c ft_memmove.c ft_strlcat.c \
ft_isascii.c ft_strncmp.c ft_isdigit.c ft_strjoin.c ft_strchr.c \
ft_putendl_fd.c ft_memset.c ft_putchar_fd.c ft_isprint.c ft_putstr_fd.c \
ft_printf.c get_next_line.c ft_clean.c
OBJ = $(SRC:.c=.o)
BSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BOBJ = $(BSRC:.c=.o)
CC = cc
CFlags = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFlags) -c $< -o $@
	
bonus: $(BOBJ) $(OBJ)
	$(AR) $(NAME) $(BOBJ) $(OBJ)

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re bonus reb
