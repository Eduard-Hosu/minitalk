/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:35:20 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/12 14:47:48 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

int	handle_char(va_list arg)
{
	char	c;
	int		count;

	c = va_arg(arg, int);
	count = write(1, &c, 1);
	return (count);
}
