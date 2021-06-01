/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:33 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/01 14:17:02 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_waiting = 1;

void	send_bit(int pid, char bit, int sleep_time)
{
	int	sig_number;

	sig_number = SIGUSR1;
	if (bit)
		sig_number = SIGUSR2;
	g_waiting = 1;
	if (kill(pid, sig_number) == -1)
	{
		write(2, "Couldn't send bit :/\n", 22);
		exit(EXIT_FAILURE);
	}
	if (sleep_time)
		usleep(sleep_time);
	while (g_waiting && !sleep_time)
	{
	}
}

void	handler(int n)
{
	(void) n;
	g_waiting = 0;
}

int	main(int ac, char **av)
{
	int		spid;
	char	*msg;

	if (ac != 3)
	{
		write(2, "Bad args :/, I need the server pid, and a message\n", 51);
		return (0);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	spid = ft_atoi(av[1]);
	msg = av[2];
	send_pid(spid, getpid(), 1000);
	send_msg(spid, msg);
}
