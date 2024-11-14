/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:08:20 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/14 17:00:19 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_ptr(void)
{
	write(2, "Error\n", 6);
	ptf_printf("Returned a null pointer...\n");
}

void	err_opn_file()
{
	write(2, "Error\n", 6);
	ptf_printf("Error opening file...\n");
	exit(-1);
}

void	not_valid(void)
{
	write(2, "Error\n", 6);
	ptf_printf("Not a valid file...\n");
	exit(-1);
}

void	post_null_ptr(t_window *window)
{
	write(2, "Error\n", 6);
	ptf_printf("Returned a null pointer...\n");
	exit_error(window);
}
