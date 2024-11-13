/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:41:07 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/09 15:06:20 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nothing(t_window *window)
{
	mlx_clear_window(window->mlx, window->mlx_win);
	paint_map(window);
	mlx_put_image_to_window(window->mlx, window->mlx_win, \
		window->player.asset, window->player.x, window->player.y);
	return (0);
}
