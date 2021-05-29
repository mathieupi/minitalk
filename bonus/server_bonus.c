/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:55 by mmehran           #+#    #+#             */
/*   Updated: 2021/05/29 02:22:32 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	read_char(int bit, int spid)
{
	static t_reading_char	reading_char = {0, 0};

	reading_char.c += bit << reading_char.count;
	reading_char.count++;
	if (reading_char.count == 8)
	{
		if (reading_char.c == 0)
			kill(spid, SIGUSR1);
		write(1, &reading_char.c, 1);
		reading_char.c = 0;
		reading_char.count = 0;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	digit = n % 10 + '0';
	write(fd, &digit, 1);
}

void	handler(int sig_number, siginfo_t *siginfo, void *context)
{
	(void) context;
	if (sig_number == SIGUSR2)
		read_char(1, siginfo->si_pid);
	else if (sig_number == SIGUSR1)
		read_char(0, siginfo->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	write(1, "my pid: ", 8);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
