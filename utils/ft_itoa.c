/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:27:57 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/01 11:45:52 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	swap(char *arr, int a, int b)
{
	char	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

static void	reverse(char *s, int len)
{
	int	i;

	i = 0;
	while (len / 2 > i)
	{
		swap(s, i, len - i - 1);
		i++;
	}
}

static void	itoa_(int n, char *p)
{
	int				i;
	int				neg;
	unsigned int	un;

	i = 0;
	neg = 0;
	un = n;
	if (n < 0)
	{
		neg = 1;
		p[i++] = '-';
		un = -n;
	}
	if (n == 0)
		p[i++] = '0';
	while (un)
	{
		p[i++] = (un % 10) + '0';
		un /= 10;
	}
	p[i] = 0;
	reverse(p + neg, i - neg);
}

static int	count(int n)
{
	int	result;

	result = 0;
	if (n <= 0)
		result++;
	while (n)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*p;

	p = malloc(count(n) + 1);
	if (p)
		itoa_(n, p);
	return (p);
}
