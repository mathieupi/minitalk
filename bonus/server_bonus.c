/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:55 by mmehran           #+#    #+#             */
/*   Updated: 2021/05/29 00:49:56 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	read_char(int bit)
{
	static t_reading_char	reading_char = {0, 0};

	reading_char.c += bit << reading_char.count;
	reading_char.count++;
	if (reading_char.count == 8)
	{
		write(1, &reading_char.c, 1);
		reading_char.c = 0;
		reading_char.count = 0;
	}
}

void	handler(int signal_number)
{
	if (signal_number == SIGUSR2)
		read_char(1);
	else if (signal_number == SIGUSR1)
		read_char(0);
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

int	main(void)
{
	write(1, "my pid: ", 8);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
