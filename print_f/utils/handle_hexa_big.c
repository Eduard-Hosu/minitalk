/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:51:05 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/21 12:52:33 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

static int	handle_ascii(int temp)
{
	if (temp < 10)
		temp += '0';
	else
		temp += 55;
	return (temp);
}

int	handle_hexa_big(va_list arg)
{
	int				temp;
	unsigned long	i;
	char			*str;
	int				pos;

	i = 0;
	i = va_arg(arg, unsigned int);
	str = malloc(20);
	pos = 0;
	if (i == 0)
	{
		str[pos] = '0';
		return (hexa_helper(str, pos));
	}
	while (i > 0)
	{
		temp = i % 16;
		temp = handle_ascii(temp);
		str[pos] = temp;
		pos++;
		temp = 0;
		i = i / 16;
	}
	return (hexa_helper(str, pos - 1));
}
