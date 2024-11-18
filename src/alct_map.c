/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alct_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:30:38 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/18 19:22:06 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	al_maps(t_window *window, int fd)
{
	int	i;

	i = 0;
	if (window->h == 50 || window->w == 50)
		not_valid();
	window->map = (char **)malloc(sizeof(char *) * (window->h / 50 + 1));
	if (window->map == NULL)
		post_null_ptr();
	while (i <= window->h / 50)
	{
		window->map[i] = get_next_line(fd);
		if (!window->map[i])
			break ;
		i++;
	}
	window->map[i] = NULL;
}

static int	c_line(char *av)
{
	int		i;
	int		fd;
	char	c;

	c = 0;
	i = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			i++;
	i += (c != '\n');
	close(fd);
	return (i);
}

static int	c_column(char *av)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	if (av == NULL)
		fd = open("maps/map0.ber", O_RDONLY);
	else
		fd = open(av, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (!c || c == '\n')
			break ;
		i++;
	}
	close(fd);
	return (i);
}

static bool	rect_map(t_window *window, int fd)
{
	const int	x_init = window->w / 50;
	const int	y_init = window->h / 50;
	char		*cl;
	int			y;

	y = 0;
	while (y < y_init)
	{
		cl = get_next_line(fd);
		if (cl == NULL)
			post_null_ptr();
		if (ft_strlen(cl) - 1 != (size_t)x_init || cl == NULL)
		{
			if (cl)
				free(cl);
			return (true);
		}
		free(cl);
		y++;
	}
	if (y != y_init)
		return (true);
	return (false);
}

int	alct_map(t_window *window, char *av)
{
	int		fd;

	if (ft_strrstr(av, ".ber") == NULL)
		not_valid();
	fd = open(av, O_RDONLY);
	if (fd < 0)
		err_opn_file();
	window->h = c_line(av) * 50;
	window->w = c_column(av) * 50;
	if (window->h > 1080 || window->w > 1920)
		map_too_big();
	if (rect_map(window, fd))
		not_valid();
	close(fd);
	fd = open(av, O_RDONLY);
	al_maps(window, fd);
	checkers(window);
	return (1);
}
