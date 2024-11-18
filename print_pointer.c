/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:29:25 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/18 01:27:37 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	con(unsigned long value, char *printout, int *length, int asc)
{
	unsigned long	tempval;
	int				i;
	int				digit;

	digit = 0;
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

int	print_pointer(unsigned long value, int asc)
{
	char	printout[17];
	char	temp;
	int		length;
	int		i;

	length = 0;
	i = 0;
	if (value == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	con(value, printout, &length, asc);
	while (i < length / 2)
	{
		temp = printout[i];
		printout[i] = printout[length - i - 1];
		printout[length - i - 1] = temp;
		i++;
	}
	ft_putstr_fd(printout, 1);
	return (length + 2);
}
