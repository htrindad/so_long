/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:54:26 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/18 16:45:00 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(little))
		return ((char *)big);
	i = ft_strlen(big);
	if (i < ft_strlen(little))
		return (NULL);
	while (i)
	{
		j = ft_strlen(little);
		if (big[i] == little[j])
		{
			while (little[j] == big[i] && j)
			{
				j--;
				i--;
			}
			if (!j)
				return ((char *)&big[i]);
		}
		i--;
	}
	return (NULL);
}
