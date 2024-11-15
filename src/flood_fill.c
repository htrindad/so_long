/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:24 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/15 15:58:31 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_ff_found = 0;

static int	all_cocs(char **map)
{
	size_t	y;
	size_t	x;
	int		cocs;

	y = 0;
	cocs = 1;
	while (map[y++])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'C')
				cocs++;
	}
	return (cocs);
}

static size_t	find_py(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y++])
	{
		x = 1;
		while (map[y][x])
			if (map[y][x++] == 'P')
				return (y);
	}
	return (0);
}

static size_t	find_px(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y++])
	{
		x = 0;
		while (map[y][x++])
			if (map[y][x] == 'P')
				return (x);
	}
	return (0);
}

static void	ff(char **map, size_t y, size_t x)
{
	g_ff_found += (map[y][x] == 'E' || map[y][x] == 'C');
	if (map[y - 1][x] != '1')
		ff(map, y - 1, x);
	if (map[y + 1][x] != '1')
		ff(map, y + 1, x);
	if (map[y][x - 1] != '1')
		ff(map, y, x - 1);
	if (map[y][x + 1] != '1')
		ff(map, y, x + 1);
	return ;
}

bool	ff_receiver(char **map)
{
	const size_t	py = find_py(map);
	const size_t	px = find_px(map);

	ff(map, py, px);
	if (g_ff_found != all_cocs(map))
		return (true);
	return (false);
}
