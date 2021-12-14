# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 13:53:24 by ehosu             #+#    #+#              #
#    Updated: 2021/10/12 13:17:13 by ehosu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
RM = rm -f

NAME = libftprintf.a

SRC = ft_printf.c utils/handle_char.c utils/handle_hexa_big.c utils/handle_hexa_small.c utils/handle_integer.c utils/handle_string.c \
		utils/handle_unsigned_decimal.c utils/handle_void_pointer.c utils/hexa_helper.c

OBJ=${SRC:.c=.o}

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJ}
	cd libft && ${MAKE} bonus
	ar rcs ${NAME} ${OBJ} ./libft/*.o

clean:
	cd libft && ${MAKE} clean
	${RM} ${OBJ}
	${RM} ${BONUS_OBJ}

fclean: clean
	cd libft && ${MAKE} fclean
	${RM} ${NAME}

re: fclean all


