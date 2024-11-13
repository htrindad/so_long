# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 17:51:27 by htrindad          #+#    #+#              #
#    Updated: 2024/05/14 14:41:37 by htrindad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_print_ung_fd.c ft_putchar_fd.c\
	ft_puthexa_fd.c ft_putnbr_fd.c ft_putptr_fd.c ft_putstr_fd.c\
	ft_strlen.c ft_toupper.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
