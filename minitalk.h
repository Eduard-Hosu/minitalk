/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:43:15 by ehosu             #+#    #+#             */
/*   Updated: 2021/12/14 11:30:55 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_C_SOURCE 199309L
# define _XOPEN_SOURCE 700
# define _DEFAULT_SOURCE 1
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "print_f/ft_printf.h"

volatile int	g_confirm = 1;

#endif
