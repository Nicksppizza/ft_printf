/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:50:38 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/10 16:02:05 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_split(char **str, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	count_word(const char *str, char c)
{
	int		i;
	int		x;
	int		count;

	i = 0;
	x = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (str[i] == c)
			x = 0;
		i++;
	}
	return (count);
}

static char	*ft_word(char const *s, int start, int end)
{
	char		*word;
	int			i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	split_words(const char *s, char c, char **res, int is_word)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && is_word < 0)
			is_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && is_word >= 0)
		{
			res[j] = ft_word(s, is_word, i);
			if (!(res[j]))
			{
				free_split (res, j);
				return (1);
			}
			is_word = -1;
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char		**res;
	int			is_word;
	int			check;

	if (!s)
		return (NULL);
	res = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	is_word = -1;
	check = split_words(s, c, res, is_word);
	if (check == 1)
		return (NULL);
	return (res);
}
