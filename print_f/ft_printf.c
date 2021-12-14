/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:09:29 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/12 15:09:05 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils/utils.h"
#include "libft/libft.h"

static int	check_handle(char handle, va_list arg)
{
	int	count;

	count = 0;
	if (handle == 'c')
		count += handle_char(arg);
	else if (handle == 'd' || handle == 'i')
		count += handle_integer(arg);
	else if (handle == 's')
		count += handle_string(arg);
	else if (handle == 'x')
		count += handle_hexa_small(arg);
	else if (handle == 'X')
		count += handle_hexa_big(arg);
	else if (handle == 'u')
		count += handle_unsigned_decimal(arg);
	else if (handle == 'p')
		count += handle_void_pointer(arg);
	return (count);
}

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		i;
	int		count_printed;

	va_start(arg, format);
	i = 0;
	count_printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count_printed += write(1, "%", 1);
			else
				count_printed += check_handle(format[i], arg);
		}
		else
			count_printed += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (count_printed);
}
