/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ung_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:42:47 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:34:41 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptf_unglen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ptf_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		i;

	i = ptf_unglen(n);
	num = malloc(sizeof(char) * (i + 1));
	if (!num)
		return (0);
	num[i] = 0;
	while (n)
	{
		num[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (num);
}

void	ptf_print_ung_fd(unsigned int n, int fd, int *len)
{
	char	*num;

	if (!n)
		ptf_putchar_fd(48, fd, len);
	else
	{
		num = ptf_unsigned_itoa(n);
		ptf_putstr_fd(num, fd, len);
		free(num);
	}
}
