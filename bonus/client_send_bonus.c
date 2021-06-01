/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:15:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/01 14:20:59 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(int pid, char c, int sleep_time)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, c & 1, sleep_time);
		c >>= 1;
		i++;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		send_char(pid, *msg, 0);
		msg++;
	}
	send_char(pid, '\n', 0);
	send_char(pid, '\0', 0);
}

void	send_pid(int pid, int my_pid, int sleep_time)
{
	char	*msg_ptr;
	char	*msg;

	msg_ptr = ft_itoa(my_pid);
	msg = msg_ptr;
	while (*msg)
	{
		send_char(pid, *msg, sleep_time);
		msg++;
	}
	send_char(pid, '\0', sleep_time);
	free(msg_ptr);
}
