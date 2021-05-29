/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:40 by mmehran           #+#    #+#             */
/*   Updated: 2021/05/29 02:04:15 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(int pid, char bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(1000);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, c & 1);
		c >>= 1;
		i++;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
	send_char(pid, '\n');
	send_char(pid, 0);
}

void	ack(int signum)
{
	(void) signum;
	write(1, "Acknowledgement received from server :)\n", 41);
	exit(0);
}

int	main(int ac, char **av)
{
	int		spid;
	char	*msg;

	if (ac != 3)
		return (0);
	spid = ft_atoi(av[1]);
	msg = av[2];
	signal(SIGUSR1, ack);
	send_msg(spid, msg);
	pause();
}
