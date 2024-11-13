/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:06:45 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/11 17:19:52 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_x(char *x)
{
	int	i;

	i = 0;
	while (x[i])
		i++;
	return (i);
}

static int	count_y(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

static bool	ver_fault_y(char **map)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 1;
	n = 0;
	while (map[n][0])
		n++;
	while (map[i][j])
	{
		while (map[i])
			i++;
		if (i != n)
			return (true);
		i = 0;
		j++;
	}
	return (false);
}

bool	validate(char **map)
{
	int	lx;
	int	ly;
	int	i;

	if (ver_fault_y(map))
		return (false);
	lx = count_x(map[0]);
	ly = count_y(map);
	i = 0;
	while (map[i])
		if (lx != count_x(map[i++]))
			return (false);
	return (true);
}
