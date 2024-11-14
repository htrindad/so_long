/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:07:36 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:25 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptf_putstr_fd(char *s, int fd, int *len)
{
	if (!s)
	{
		*len += write(fd, "(null)", 6);
		return ;
	}
	*len += write(fd, s, ptf_strlen(s));
}
