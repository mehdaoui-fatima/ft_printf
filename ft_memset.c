/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:42:27 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/11/06 11:28:34 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long i;
	unsigned char *str;

	i = 0;
	str = (unsigned char*)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return ((void*)str);
}
