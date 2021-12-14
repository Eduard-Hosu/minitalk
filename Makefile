# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 17:05:17 by ehosu             #+#    #+#              #
#    Updated: 2021/12/14 17:16:58 by ehosu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
HEADER = minitalk.h
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
RM = rm -rf

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all:	$(CLIENT_NAME) $(SERVER_NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(SERVER_NAME):	$(OBJS_SERVER)
	cd print_f && ${MAKE}
	$(CC) -o $(SERVER_NAME) $(CFLAGS) $(OBJS_SERVER) ./print_f/libftprintf.a

$(CLIENT_NAME):	$(OBJS_CLIENT)
	cd print_f && ${MAKE}
	$(CC) -o $(CLIENT_NAME) $(CFLAGS) $(OBJS_CLIENT) ./print_f/libftprintf.a

clean:
	cd print_f && ${MAKE} clean
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT} ./print_f/libftprintf.a

fclean: clean
	${RM} $(CLIENT_NAME) $(SERVER_NAME)

re:	fclean all

.PHONY:
	all clean fclean re