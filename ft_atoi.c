/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:26:38 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/24 15:48:30 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_atoi(const char *s)
{
	int				i;
	unsigned long	res;
	int				n;

	i = 0;
	res = 0;
	n = 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
			|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		n = (s[i] == '-') ? -1 : 1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		if (res > LONG_MAX && n == 1)
			return (-1);
		if (res > LONG_MAX && n == -1)
			return (0);
		i++;
	}
	return ((int)(res * n));
}
