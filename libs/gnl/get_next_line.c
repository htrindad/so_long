/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:26:27 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/09 14:54:28 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	next_l[BUFFER_SIZE + 1];
	int			chars_r;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(1);
	if (buff == NULL)
		return (NULL);
	buff[0] = 0;
	buff = gnl_strjoin(buff, next_l);
	if (check_and_clear(next_l))
		return (buff);
	chars_r = read(fd, next_l, BUFFER_SIZE);
	if (chars_r < 1 && (!*buff))
		return (free_gnl(buff));
	while (chars_r > 0)
	{
		next_l[chars_r] = 0;
		buff = gnl_strjoin(buff, next_l);
		if (check_and_clear(next_l))
			break ;
		chars_r = read(fd, next_l, BUFFER_SIZE);
	}
	return (buff);
}
