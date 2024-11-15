/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:10:12 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/15 12:52:46 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_map(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' \
				&& map[y][x] != 'C' && map[y][x] != 'P' \
				&& map[y][x] != 'E' && map[y][x] != '\n')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

static bool	pce(char **map)
{
	size_t	p;
	size_t	c;
	size_t	e;
	size_t	y;
	size_t	x;

	p = 0;
	c = 0;
	e = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			p += map[y][x] == 'P';
			c += map[y][x] == 'C';
			e += map[y][x] == 'E';
		}
	}
	if (p != 1 || C < 1 || e != 1)
		return (false);
	return (true);
}

void	checkers(t_window *window)
{
	if (check_map(window->map) || pce(window->map))
		invalid_map(window);
}
