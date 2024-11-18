/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:29:52 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/18 01:36:33 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	con(unsigned int value, char *printout, int *length, int asc)
{
	unsigned int	tempval;
	int				digit;
	int				i;

	i = 0;
	tempval = value;
	while (tempval != 0)
	{
		digit = tempval % 16;
		if (digit < 10)
			printout[i] = digit + '0';
		else
			printout[i] = digit + asc;
		tempval /= 16;
		i++;
	}
	*length = i;
	printout[i] = '\0';
}

int	print_hex(unsigned int value, int asc)
{
	char	printout[9];
	int		length;
	char	temp;
	int		i;

	length = 0;
	i = 0;
	if (value == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	con(value, printout, &length, asc);
	while (i < length / 2)
	{
		temp = printout[i];
		printout[i] = printout[length - i - 1];
		printout[length - i - 1] = temp;
		i++;
	}
	ft_putstr_fd(printout, 1);
	return (length);
}
