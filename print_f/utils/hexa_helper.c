/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:48:57 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/25 12:04:21 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

int	hexa_helper(char *str, int pos)
{
	int		count;

	count = 0;
	while (pos >= 0)
	{
		count += write(1, &str[pos], 1);
		pos--;
	}
	free(str);
	return (count);
}

int	helper(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}
