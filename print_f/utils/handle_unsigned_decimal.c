/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:53:27 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/14 12:35:34 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../libft/libft.h"
#include <unistd.h>

static char	*ft_utoa(unsigned int n)
{
	char	*result;
	int		n_length;

	n_length = numb_length(n);
	result = (char *)malloc(n_length + 1);
	if (result == NULL)
		return (NULL);
	make_string(result, n, n_length, 0);
	return (result);
}

static int	unsigned_decimal_helper(unsigned int i)
{
	int		count;
	int		j;
	char	*str;

	j = 0;
	count = 0;
	str = ft_utoa(i);
	while (str[j])
	{
		count += write(1, &str[j], 1);
		j++;
	}
	free(str);
	return (count);
}

int	handle_unsigned_decimal(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	return (unsigned_decimal_helper(i));
}
