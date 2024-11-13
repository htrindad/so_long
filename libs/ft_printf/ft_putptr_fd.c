/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:49:58 by htrindad          #+#    #+#             */
/*   Updated: 2024/05/10 18:47:21 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr /= 16;
	}
	return (i);
}

static void	ft_ptr(uintptr_t ptr, int fd, int *len)
{
	if (ptr > 15)
	{
		ft_ptr(ptr / 16, fd, len);
		ft_ptr(ptr % 16, fd, len);
	}
	else
	{
		if (ptr < 10)
			ft_putchar_fd((ptr + 48), fd, len);
		else
			ft_putchar_fd((ptr - 10 + 97), fd, len);
	}
}

void	ft_putptr_fd(unsigned long long ptr, int fd, int *print_l)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd, print_l);
		return ;
	}
	ft_putstr_fd("0x", fd, print_l);
	ft_ptr(ptr, fd, print_l);
	print_l += ft_ptr_len(ptr);
}
