/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:29:53 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/13 17:35:55 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_cocs(t_window *window)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (window->map[y])
	{
		while (window->map[y][x])
		{
			if (window->map[y][x] == 'C')
				window->player.cocs++;
			x++;
		}
		y++;
		x = 0;
	}
}
