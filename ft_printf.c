/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalaoui <ahalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:30:39 by ahalaoui          #+#    #+#             */
/*   Updated: 2024/11/18 01:45:53 by ahalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *input, void *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i = i + print_char((int)arg);
	else if (*input == 's')
		i = i + print_string((char *)arg);
	else if (*input == 'p')
		i = i + print_pointer((unsigned long)arg, 87);
	else if (*input == 'd' || *input == 'i')
		i = i + print_int((int)arg);
	else if (*input == 'u')
		i = i + print_unsigned((unsigned int)arg);
	else if (*input == 'x')
		i = i + print_hex((unsigned int)arg, 87);
	else if (*input == 'X')
		i = i + print_hex((unsigned int)arg, 55);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			arg;
	unsigned int	i;
	unsigned int	j;

	if (write(1, 0, 0) == -1)
		return (-1);
	j = 0;
	i = 0;
	va_start(arg, input);
	while (input[j] != '\0')
	{
		if (input[j] == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", input[j]))
				i = i + check_type(&input[j], va_arg(arg, void *));
			else if (input[j] == '%')
				i = i + print_char('%');
		}
		else
			i = i + print_char(input[j]);
		j++;
	}
	va_end(arg);
	return (i);
}
