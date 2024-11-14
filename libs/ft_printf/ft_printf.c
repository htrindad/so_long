/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:18:17 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:25 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ptf_callarg(va_list args, char c, int *print_l)
{
	char	casing[2];

	casing[0] = 37;
	casing[1] = c;
	if (c == 99)
		ptf_putchar_fd(va_arg(args, int), 1, print_l);
	else if (c == 115)
		ptf_putstr_fd(va_arg(args, char *), 1, print_l);
	else if (c == 112)
		ptf_putptr_fd(va_arg(args, unsigned long long), 1, print_l);
	else if (c == 100 || c == 105)
		ptf_putnbr_fd(va_arg(args, int), 1, print_l);
	else if (c == 117)
		ptf_print_ung_fd(va_arg(args, unsigned int), 1, print_l);
	else if (c == 37)
		ptf_putchar_fd(37, 1, print_l);
	else if (c == 120)
		ptf_puthexa_fd(va_arg(args, unsigned int), 1, print_l, false);
	else if (c == 88)
		ptf_puthexa_fd(va_arg(args, unsigned int), 1, print_l, true);
	else
		ptf_putstr_fd(casing, 1, print_l);
}

int	ptf_printf(const char *s, ...)
{
	int		*print_l;
	va_list	args;
	int		print_c;

	if (!s)
		return (-1);
	print_c = 0;
	print_l = &print_c;
	va_start(args, s);
	while (*s)
	{
		if (*s == 37)
		{
			s++;
			ptf_callarg(args, *s, print_l);
		}
		else
			ptf_putchar_fd(*s, 1, print_l);
		s++;
	}
	va_end(args);
	return (print_c);
}
