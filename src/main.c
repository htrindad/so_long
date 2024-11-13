/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:49:16 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/13 18:11:10 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_all(t_window *window, char *av)
{
	window->player.cocs = 0;
	alct_map(window, av);
	set_pos(window);
	set_cocs(window);
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		null_ptr();
	window->mlx_win = mlx_new_window(window->mlx, \
		window->w, window->h, "so_long");
}

static void	load_imgs(t_window *window)
{
	int	p;

	window->player.asset = mlx_xpm_file_to_image(window->mlx, \
		"assets/char.xpm", &p, &p);
	window->wall = mlx_xpm_file_to_image(window->mlx, \
		"assets/wall.xpm", &p, &p);
	window->collectible = mlx_xpm_file_to_image(window->mlx, \
		"assets/collectible.xpm", &p, &p);
	window->exit = mlx_xpm_file_to_image(window->mlx, \
		"assets/exit.xpm", &p, &p);
}

int	main(int ac, char **av)
{
	static t_window	window;

	(void)ac;
	initialize_all(&window, av[1]);
	load_imgs(&window);
	mlx_loop_hook(window.mlx, nothing, &window);
	mlx_hook(window.mlx_win, 17, 0, exit_win, &window);
	mlx_key_hook(window.mlx_win, keypress, &window);
	mlx_loop(window.mlx);
}
