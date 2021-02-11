/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:24:01 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/29 20:10:16 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	*ft_strr(char *p)
{
	int		i;
	int		k;
	char	c;
	int		len;

	i = 0;
	len = ft_strlen(p) - 1;
	k = len;
	while (i <= len / 2 && k >= len / 2)
	{
		c = p[i];
		p[i] = p[k];
		p[k] = c;
		k--;
		i++;
	}
	return (p);
}

char	*ft_tohexa(unsigned long n, char c)
{
	static char hexa[] = "0123456789ABCDEF";
	char		*p;
	int			i;

	i = 0;
	p = (char*)malloc(sizeof(char) * 40);
	ft_memset(p, '\0', 39);
	while (n / 16 > 0)
	{
		if (c == 'x')
			p[i++] = ft_tolower(hexa[n % 16]);
		else
			p[i++] = hexa[n % 16];
		n = n / 16;
	}
	if (c == 'x')
		p[i++] = ft_tolower(hexa[n % 16]);
	else
		p[i++] = hexa[n % 16];
	p[i + 1] = '\0';
	p = ft_strr(p);
	return (p);
}
