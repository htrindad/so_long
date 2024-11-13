/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:07:36 by htrindad          #+#    #+#             */
/*   Updated: 2024/05/17 11:50:21 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *len)
{
	if (!s)
	{
		*len += write(fd, "(null)", 6);
		return ;
	}
	*len += write(fd, s, ft_strlen(s));
}
