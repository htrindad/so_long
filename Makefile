NAME = so_long

MLX_DIR = ./libs/mlx
MLX = $(MLX_DIR)/libmlx.a

NEO_LIBFT_DIR = ./libs/neo_libft
NEO_LIBFT = $(NEO_LIBFT_DIR)/neo_libft.a

GNL_DIR = ./libs/gnl
GNL = $(GNL_DIR)/gnl.a

FT_PRINTF_DIR = ./libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

S_DIR = ./src
SRC = $(S_DIR)/main.c $(S_DIR)/keypresses.c $(S_DIR)/exit_win.c $(S_DIR)/refresh.c $(S_DIR)/move.c \
      $(S_DIR)/error_handler.c $(S_DIR)/alct_map.c $(S_DIR)/paint_map.c $(S_DIR)/set_cocs.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L. -lXext -L. -lX11

$(NAME): $(NEO_LIBFT) $(MLX) $(GNL) $(FT_PRINTF) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(NEO_LIBFT) $(GNL) $(FT_PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

all: $(NAME)

$(NEO_LIBFT):
	make -s -C $(NEO_LIBFT_DIR)

$(MLX):
	make -s -C $(MLX_DIR)

$(GNL):
	make -s -C $(GNL_DIR)

$(FT_PRINTF):
	make -s -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_DIR)
	make fclean -C $(NEO_LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all
