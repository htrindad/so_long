/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:14:25 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/15 15:26:40 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(t_window *window)
{
	write(2, "Error\n", 6);
	ptf_printf("Invalid map...\n");
	free_string(window);
	exit(-1);
}
