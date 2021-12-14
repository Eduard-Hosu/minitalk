/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_void_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:02:07 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/21 12:31:46 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../libft/libft.h"
#include <unistd.h>

static int	handle_ascii(int temp)
{
	if (temp < 10)
		temp += '0';
	else
		temp += 87;
	return (temp);
}

int	handle_void_pointer(va_list arg)
{
	int				temp;
	unsigned long	i;
	char			*str;
	int				pos;

	i = 0;
	i = va_arg(arg, unsigned long);
	if (!i)
		return (helper("0x0"));
	str = (char *)ft_calloc((numb_length(i) + 1), sizeof(char));
	if (str == NULL)
		return (helper("(null)"));
	pos = 0;
	temp = 0;
	while (i > 0)
	{
		temp = i % 16;
		temp = handle_ascii(temp);
		str[pos] = temp;
		pos++;
		temp = 0;
		i = i / 16;
	}
	str = ft_strjoin(str, "x0");
	return (hexa_helper(str, pos + 1));
}
