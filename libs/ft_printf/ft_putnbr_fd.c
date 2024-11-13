/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:05:58 by htrindad          #+#    #+#             */
/*   Updated: 2024/05/10 18:48:07 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int *len)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd, len);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd(45, fd, len);
			n = -n;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd, len);
		ft_putchar_fd(n % 10 + 48, fd, len);
	}
}
