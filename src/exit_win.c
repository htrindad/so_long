/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:31:20 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:35:54 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_string(t_window *window)
{
	int	i;

	i = 0;
	while (window->map[i])
		free(window->map[i++]);
	free(window->map);
}

static void	destroy_assets(t_window *window)
{
	mlx_destroy_image(window->mlx, \
		window->player.asset);
	mlx_destroy_image(window->mlx, \
		window->wall);
	mlx_destroy_image(window->mlx, \
		window->collectible);
	mlx_destroy_image(window->mlx, \
		window->exit);
}

void	exit_error(t_window *window)
{
	free_string(window);
	destroy_assets(window);
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(0);
}

int	exit_win(t_window *window)
{
	ptf_printf("Be seeing you...\n");
	exit_error(window);
	return (0);
}
