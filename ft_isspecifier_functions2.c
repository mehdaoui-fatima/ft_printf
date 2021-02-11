/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecifier_functions2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:53:06 by fmehdaou          #+#    #+#             */
/*   Updated: 2020/01/03 20:53:09 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	*c_to_s(char c)
{
	char *tmp;

	tmp = (char *)malloc(2 * sizeof(char));
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

void	ft_isspecifier_c(char **formatp,
			t_specifier *sp, va_list a_list)
{
	char c;

	c = va_arg(a_list, int);
	if (c == '\0')
		sp->end = 'y';
	*formatp = c_to_s(c);
	sp->type = 'c';
	sp->ch = 'c';
}

void	ft_build_sp(t_specifier *sp)
{
	sp->sign = '+';
	sp->type = 'n';
	sp->p = 'l';
	sp->special = 'm';
	sp->end = 'n';
	sp->ch = 'k';
}

void	ft_isspecifier_xu(const char *format, char **formatp,
						va_list a_list, long *n)
{
	int j;

	j = 0;
	*n = va_arg(a_list, unsigned int);
	if (format[j] == 'x')
		*formatp = ft_tohexa(*n, 'x');
	else if (format[j] == 'X')
		*formatp = ft_tohexa(*n, 'X');
	else
		*formatp = ft_itoa(*n);
}
