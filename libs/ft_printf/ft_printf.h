/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:54:08 by htrindad          #+#    #+#             */
/*   Updated: 2024/05/18 17:24:14 by htrindad         ###   ########.fr       */
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

int			ft_strlen(const char *str);
void		ft_putchar_fd(char c, int fd, int *len);
void		ft_putnbr_fd(int n, int fd, int *len);
void		ft_putstr_fd(char *s, int fd, int *len);
int			ft_printf(const char *s, ...);
void		ft_putptr_fd(unsigned long long ptr, int fd, int *len);
void		ft_print_ung_fd(unsigned int n, int fd, int *len);
void		ft_puthexa_fd(unsigned int hex, int fd, int *len, bool cap);
void		ft_toupper(char *s);

#endif
