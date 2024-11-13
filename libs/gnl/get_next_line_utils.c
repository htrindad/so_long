/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:05:58 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/09 14:47:11 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i += str[i] == '\n';
	return (i);
}

char	*gnl_strjoin(char *dest, char const *src)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (NULL);
	str = malloc(gnl_strlen(dest) + gnl_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
	{
		str[i] = dest[i];
		i++;
	}
	while (src[j] && src[j] != '\n')
		str[i++] = src[j++];
	if (src[j] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	free(dest);
	return (str);
}

int	check_and_clear(char *line)
{
	int	i;
	int	j;
	int	flag;

	if (!line)
		return (0);
	i = 0;
	j = 0;
	flag = 0;
	while (line[i])
	{
		if (flag)
			line[j++] = line[i];
		if (line[i] == '\n')
			flag = 1;
		line[i++] = 0;
	}
	return (flag);
}

char	*free_gnl(char *gnl)
{
	free(gnl);
	return (NULL);
}
