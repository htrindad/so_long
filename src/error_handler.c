/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:08:20 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/13 17:08:56 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_ptr(void)
{
	write(2, "Error\n", 6);
	ft_printf("Returned a null pointer...\n");
}

void	err_opn_file(t_window *window)
{
	write(2, "Error\n", 6);
	ft_printf("Error opening file...\n");
	exit_error(window);
}

void	not_valid(t_window *window)
{
	write(2, "Error\n", 6);
	ft_printf("Not a valid file...\n");
	exit_error(window);
}

void	post_null_ptr(t_window *window)
{
	write(2, "Error\n", 6);
	ft_printf("Returned a null pointer...\n");
	exit_error(window);
}
