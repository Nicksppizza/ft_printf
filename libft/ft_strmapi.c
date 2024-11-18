/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:01:26 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/05 15:22:18 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char					*str;
	unsigned int			i;
	unsigned int			slen;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	str = malloc((slen + 1) * (sizeof (char)));
	if (!str)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		str[i] = (f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
