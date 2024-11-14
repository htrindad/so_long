/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:54:08 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 14:34:24 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

int			ptf_strlen(const char *str);
void		ptf_putchar_fd(char c, int fd, int *len);
void		ptf_putnbr_fd(int n, int fd, int *len);
void		ptf_putstr_fd(char *s, int fd, int *len);
int			ptf_printf(const char *s, ...);
void		ptf_putptr_fd(unsigned long long ptr, int fd, int *len);
void		ptf_print_ung_fd(unsigned int n, int fd, int *len);
void		ptf_puthexa_fd(unsigned int hex, int fd, int *len, bool cap);
void		ptf_toupper(char *s);

#endif
