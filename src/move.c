/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:58:29 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:36:15 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	detect_collision(char dir, t_window *window)
{
	int const	x = window->player.x / 50;
	int const	y = window->player.y / 50;

	if (dir == 1 && window->map[y - 1][x] != '1')
		window->player.y -= 50;
	if (dir == 2 && window->map[y + 1][x] != '1')
		window->player.y += 50;
	if (dir == 3 && window->map[y][x - 1] != '1')
		window->player.x -= 50;
	if (dir == 4 && window->map[y][x + 1] != '1')
		window->player.x += 50;
}

static void	detect_collectible(t_window *window)
{
	int const	x = window->player.x / 50;
	int const	y = window->player.y / 50;

	if (window->map[y][x] == 'C')
	{
		window->map[y][x] = '0';
		window->player.cocs--;
	}
}

static void	detect_exit(t_window *window)
{
	int const	x = window->player.x / 50;
	int const	y = window->player.y / 50;

	if (!window->player.cocs && window->map[y][x] == 'E')
		exit_win(window);
}

void	move(char dir, t_window *window)
{
	window->player.moves++;
	ptf_printf("Moved: ");
	detect_collision(dir, window);
	if (dir == 1)
		ptf_printf("Up\n");
	if (dir == 2)
		ptf_printf("Down\n");
	if (dir == 3)
		ptf_printf("Left\n");
	if (dir == 4)
		ptf_printf("Right\n");
	detect_collectible(window);
	detect_exit(window);
	ptf_printf("Current moves: %d\n", window->player.moves);
}
