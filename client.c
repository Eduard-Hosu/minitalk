/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:07:02 by ehosu             #+#    #+#             */
/*   Updated: 2021/12/14 17:13:45 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_pause(void)
{
	while (g_confirm)
		;
	usleep(100);
	g_confirm = 1;
}

void	handle_response(int sing)
{
	if (sing == SIGUSR1)
		g_confirm = 0;
	else
		ft_printf("Message recived!\n");
}

void	send_massage(char *str, int server_id)
{
	unsigned char	mask;
	int				i;

	i = 0;
	while (str[i])
	{
		mask = 0b10000000;
		while (mask)
		{
			if (str[i] & mask)
				kill(server_id, SIGUSR1);
			else
				kill(server_id, SIGUSR2);
			my_pause();
			mask >>= 1;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(server_id, SIGUSR2);
		my_pause();
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	response;

	if (argc != 3)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	response.sa_flags = SA_SIGINFO;
	response.sa_handler = handle_response;
	sigaction(SIGUSR1, &response, NULL);
	sigaction(SIGUSR2, &response, NULL);
	send_massage(argv[2], ft_atoi(argv[1]));
	return (1);
}
