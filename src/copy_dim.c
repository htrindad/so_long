/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:08:17 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/15 16:36:03 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_dim(char **map)
{
	size_t	y;
	char	**cpy;

	y = 0;
	while (map[y])
		y++;
	cpy = (char **)malloc((y + 1) * sizeof(char *));
	if (cpy == NULL)
		return (free_str(cpy));
	y = 0;
	while (map[y])
	{
		cpy[y] = ft_strdup(map[y]);
		if (cpy[y++] == NULL)
			return (free_str(cpy));
	}
	cpy[y] = NULL;
	return (cpy);
}
