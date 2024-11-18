/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:32:34 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/10 14:02:14 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*str;
	size_t		slen;
	size_t		dlen;
	size_t		i;
	size_t		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	i = 0;
	j = 0;
	slen = ft_strlen (s1);
	dlen = ft_strlen (s2);
	str = malloc ((slen + dlen + 1) * (sizeof (char)));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	return (str[i] = '\0', str);
}
