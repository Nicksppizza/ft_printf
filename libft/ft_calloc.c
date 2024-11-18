/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:38:30 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/03 17:12:24 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	total_size = count * size;
	ptr = malloc (total_size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, total_size);
	return (ptr);
}
