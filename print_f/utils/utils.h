/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:11:31 by ehosu             #+#    #+#             */
/*   Updated: 2021/10/21 12:33:51 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	handle_char(va_list arg);
int	handle_hexa_big(va_list arg);
int	handle_hexa_small(va_list arg);
int	handle_integer(va_list arg);
int	handle_string(va_list arg);
int	handle_unsigned_decimal(va_list arg);
int	handle_void_pointer(va_list arg);
int	hexa_helper(char *str, int pos);
int	helper(char *str);

#endif
