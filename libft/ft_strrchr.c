/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:38:07 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/08 17:24:50 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	uc;

	uc = (char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == uc)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
