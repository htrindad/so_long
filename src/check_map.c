/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:10:12 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/15 15:53:00 by htrindad         ###   ########.fr       */
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
			x++;
		}
		y++;
	}
	if (p != 1 || c < 1 || e != 1)
		return (true);
	return (false);
}

static bool	line_one(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '\n')
			return (true);
		i++;
	}
	return (false);
}

static bool	m_open(char **map)
{
	size_t	y;

	y = 0;
	if (line_one(map[0]))
		return (true);
	while (map[y++ + 1])
		if (map[y][0] != '1' || map[y][ft_strlen(map[y]) - 2] != '1')
			return (true);
	if (line_one(map[--y]))
		return (true);
	return (false);
}

void	checkers(t_window *window)
{
	if (check_map(window->map) || pce(window->map) \
		|| m_open(window->map) || ff_receiver(window->map))
		invalid_map(window);
}
