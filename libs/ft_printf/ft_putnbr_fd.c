/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:05:58 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:57 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptf_putnbr_fd(int n, int fd, int *len)
{
	if (n == -2147483648)
		ptf_putstr_fd("-2147483648", fd, len);
	else
	{
		if (n < 0)
		{
			ptf_putchar_fd(45, fd, len);
			n = -n;
		}
		if (n > 9)
			ptf_putnbr_fd(n / 10, fd, len);
		ptf_putchar_fd(n % 10 + 48, fd, len);
	}
}
