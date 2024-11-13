/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alct_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:30:38 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/13 18:16:07 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	al_maps(t_window *window, int fd)
{
	int	i;

	i = 0;
	if (window->h == 50)
		not_valid(window);
	window->map = (char **)malloc(sizeof(char *) * (window->h / 50 + 1));
	if (!window->map)
		post_null_ptr(window);
	while (i <= window->h / 50)
	{
		window->map[i] = get_next_line(fd);
		if (!window->map[i])
			break ;
		i++;
	}
	window->map[i] = NULL;
}

static int	c_line(t_window *window, char *av)
{
	int		i;
	int		fd;
	char	c;

	c = 0;
	i = 0;
	if (av == NULL)
		fd = open("maps/map0.ber", O_RDONLY);
	else
		fd = open(av, O_RDONLY);
	if (fd < 0)
		err_opn_file(window);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			i++;
	if (c != '\n')
		i++;
	close(fd);
	return (i);
}

static int	c_column(t_window *window, char *av)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	if (av == NULL)
		fd = open("maps/map0.ber", O_RDONLY);
	else
		fd = open(av, O_RDONLY);
	if (fd < 0)
		err_opn_file(window);
	while (read(fd, &c, 1) > 0)
	{
		if (!c || c == '\n')
			break ;
		i++;
	}
	close(fd);
	return (i);
}

int	alct_map(t_window *window, char *av)
{
	int	fd;

	if (av == NULL)
		fd = open("maps/map0.ber", O_RDONLY);
	else
		fd = open(av, O_RDONLY);
	window->h = c_line(window, av) * 50;
	window->w = c_column(window, av) * 50;
	al_maps(window, fd);
	close(fd);
	return (1);
}
