# It is worth mentioning that C static libraries do not accept dependencies.
# So here, it is not possible to rely on the already built libft.a, instead
# need to compile again the files (.c -> .o). `ar` will just group these .o
# together. `ar -x libftprint.a` to see the result.

NAME = libftprintf.a
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
	  directive_parsers_1.c \
	  directive_parsers_2.c \
	  handler_char.c \
	  handler_string.c \
	  handler_signed_int.c \
	  handler_unsigned_int.c \
	  handler_float.c \
	  handler_pourcent.c \
	  handler_generics.c \
	  signed_int_to_str.c \
	  unsigned_int_to_str.c \
	  dir_to_arg_1.c \
	  dir_to_arg_2.c \
	  dir_to_arg_3.c \
	  utils.c \
	  \
	  libft/ft_atoi.c \
	  libft/ft_bzero.c \
	  libft/ft_isdigit.c \
	  libft/ft_putchar.c \
	  libft/ft_putstr.c \
	  libft/ft_strcat.c \
	  libft/ft_strcpy.c \
	  libft/ft_strdup.c \
	  libft/ft_strlen.c \
	  libft/ft_strnew.c \
	  libft/ft_strsub.c

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	ar rcs $@ $^

%.o: %.c
	$(CC) $(FLAGS) -I libft -o $@ -c $<

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all
