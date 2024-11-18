/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:37:26 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/07 11:22:08 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ld;
	size_t	ls;

	if (dstsize == 0 && !dst)
		return (ft_strlen(src));
	i = 0;
	ld = 0;
	ls = 0;
	while (dst[ld] && ld < dstsize)
		ld++;
	while (src[ls])
		ls++;
	if (ld == dstsize)
		return (ld + ls);
	if (ld < dstsize - 1)
	{
		while (src[i] && (ld + i) < dstsize - 1)
		{
			dst[ld + i] = src[i];
			i++;
		}
		dst[ld + i] = '\0';
	}
	return (ld + ls);
}
