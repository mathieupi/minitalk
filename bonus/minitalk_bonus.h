/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:51 by mmehran           #+#    #+#             */
/*   Updated: 2021/05/29 00:57:27 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_reading_char
{
	char	c;
	int		count;
}		t_reading_char;

int	ft_atoi(const char *str);

#endif
