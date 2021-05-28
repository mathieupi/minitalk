/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:28 by mmehran           #+#    #+#             */
/*   Updated: 2021/05/28 17:14:28 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	read_char(int bit)
{
	static t_rchar	rchar = {0, 0};

	rchar.c += bit << rchar.rbit;
	rchar.rbit++;
	if (rchar.rbit == 8)
	{
		write(1, &rchar.c, 1);
		rchar.c = 0;
		rchar.rbit = 0;
	}
}

void	sighandler(int signum)
{
	if (signum == SIGUSR2)
		read_char(1);
	else if (signum == SIGUSR1)
		read_char(0);
}

int	main(void)
{
	write(1, "my pid: ", 8);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
}
