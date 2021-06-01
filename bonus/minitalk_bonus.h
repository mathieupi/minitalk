/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:13 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/01 14:20:55 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

typedef struct s_reading_char
{
	char	c;
	int		count;
	int		tpid;
	int		pid;
}		t_reading_char;

char	*ft_itoa(int n);
int		ft_atoi(const char *str);

void	send_char(int pid, char c, int sleep_time);
void	send_msg(int pid, char *msg);
void	send_pid(int pid, int my_pid, int sleep_time);
void	send_bit(int pid, char bit, int sleep_time);

#endif
