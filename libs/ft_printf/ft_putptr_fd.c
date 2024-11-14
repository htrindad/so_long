/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:49:58 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:15 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptf_ptr_len(uintptr_t ptr)
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

static void	ptf_ptr(uintptr_t ptr, int fd, int *len)
{
	if (ptr > 15)
	{
		ptf_ptr(ptr / 16, fd, len);
		ptf_ptr(ptr % 16, fd, len);
	}
	else
	{
		if (ptr < 10)
			ptf_putchar_fd((ptr + 48), fd, len);
		else
			ptf_putchar_fd((ptr - 10 + 97), fd, len);
	}
}

void	ptf_putptr_fd(unsigned long long ptr, int fd, int *print_l)
{
	if (!ptr)
	{
		ptf_putstr_fd("(nil)", fd, print_l);
		return ;
	}
	ptf_putstr_fd("0x", fd, print_l);
	ptf_ptr(ptr, fd, print_l);
	print_l += ptf_ptr_len(ptr);
}
