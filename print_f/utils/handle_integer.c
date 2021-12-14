/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:42:07 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/20 14:53:23 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../libft/libft.h"
#include <unistd.h>

int	handle_integer(va_list arg)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = va_arg(arg, int);
	str = ft_itoa(i);
	count = 0;
	j = 0;
	while (str[j])
	{
		count += write(1, &str[j], 1);
		j++;
	}
	free(str);
	return (count);
}
