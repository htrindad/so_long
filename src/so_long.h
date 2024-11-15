/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:49:33 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/15 17:27:47 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/neo_libft/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/gnl/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define S 115
# define A 97
# define D 100

typedef struct s_player
{
	int		x;
	int		y;
	void	*asset;
	int		moves;
	int		cocs;
}	t_player;

typedef struct s_window
{
	t_player	player;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	void		*wall;
	void		*collectible;
	void		*exit;
	int			w;
	int			h;
}	t_window;

int		keypress(int keycode, t_window *window);
int		nothing(t_window *window);
int		exit_win(t_window *window);
int		alct_map(t_window *window, char *av);
void	move(char dir, t_window *window);
void	null_ptr(void);
void	exit_error(t_window *window);
void	err_opn_file(void);
void	paint_map(t_window *window);
void	not_valid(void);
void	post_null_ptr(void);
void	set_pos(t_window *window);
void	set_cocs(t_window *window);
void	not_eng_args(void);
void	invalid_map(t_window *window);
void	free_string(t_window *window);
void	checkers(t_window *window);
bool	ff_receiver(char **map);
char	**free_str(char **map);
char	**copy_dim(char **map);
void	map_too_big(void);

#endif
