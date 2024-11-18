/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:32:40 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/09 23:46:37 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*c_src;
	char		*c_dst;

	if (!dst && !src)
		return (NULL);
	c_src = (const char *)src;
	c_dst = (char *)dst;
	if (c_dst > c_src)
	{
		while (len > 0)
		{
			len--;
			c_dst[len] = c_src[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
