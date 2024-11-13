/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:03:38 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/13 17:55:38 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	case_bit(t_window *window, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(window->mlx, window->mlx_win, \
			window->wall, i * 50, j * 50);
	if (c == 'C')
		mlx_put_image_to_window(window->mlx, window->mlx_win, \
			window->collectible, i * 50, j * 50);
	if (c == 'E' && !window->player.cocs)
		mlx_put_image_to_window(window->mlx, window->mlx_win, \
			window->exit, i * 50, j * 50);
}

void	set_pos(t_window *window)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (window->map[j])
	{
		while (window->map[j][i])
		{
			if (window->map[j][i] == 'P')
			{
				window->player.y = j * 50;
				window->player.x = i * 50;
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	paint_map(t_window *window)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (window->map[j])
	{
		while (window->map[j][i])
		{
			case_bit(window, window->map[j][i], i, j);
			i++;
		}
		i = 0;
		j++;
	}
}
