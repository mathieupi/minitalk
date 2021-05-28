/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:14:13 by mmehran           #+#    #+#             */
/*   Updated: 2021/05/28 17:14:21 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_rchar
{
	char	c;
	int		rbit;
}		t_rchar;

#endif
