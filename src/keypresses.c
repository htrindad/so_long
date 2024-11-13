/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:29:43 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/09 13:05:26 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_window *window)
{
	if (keycode == LEFT || keycode == A)
		move(3, window);
	else if (keycode == RIGHT || keycode == D)
		move(4, window);
	else if (keycode == UP || keycode == W)
		move(1, window);
	else if (keycode == DOWN || keycode == S)
		move(2, window);
	else if (keycode == ESC)
		exit_win(window);
	return (0);
}
