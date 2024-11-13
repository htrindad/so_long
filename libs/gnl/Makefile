NAME = gnl.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
