/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:15:59 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:44 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ptf_hexalen(unsigned int hex)
{
	unsigned int	i;

	i = 0;
	while (hex)
	{
		i++;
		hex /= 16;
	}
	return (i);
}

static uint8_t	ptf_free_all(char *num)
{
	if (!num)
	{
		free(num);
		return (0);
	}
	return (1);
}

static char	ptf_setnum(unsigned int calc)
{
	const char	*set = "0123456789abcdef";

	return (set[calc]);
}

static char	*ptf_ol(unsigned int hex)
{
	char	*num;

	num = malloc(sizeof(char) * 2);
	if (!ptf_free_all(num))
		return (0);
	num[1] = 0;
	num[0] = ptf_setnum(hex);
	return (num);
}

void	ptf_puthexa_fd(unsigned int hex, int fd, int *len, bool cap)
{
	char			*num;
	unsigned int	size;

	size = ptf_hexalen(hex);
	if (size < 2)
		num = ptf_ol(hex);
	else
	{
		num = malloc(sizeof(char) * (size + 1));
		if (!ptf_free_all(num))
			return ;
		num[size] = 0;
		while (size--)
		{
			num[size] = ptf_setnum(hex % 16);
			hex /= 16;
		}
	}
	if (cap)
		ptf_toupper(num);
	ptf_putstr_fd(num, fd, len);
	free(num);
}
