/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:37:17 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/07 17:12:16 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*data;

	data = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		data[i] = c;
		i++;
	}
	return ((unsigned char *)str);
}
