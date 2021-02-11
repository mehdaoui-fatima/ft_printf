/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:32:20 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/30 14:59:45 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

t_specifier	ft_isspecifier(const char *format, int *i,
							char **formatp, va_list a_list)
{
	int			j;
	t_specifier sp;
	long		n;

	j = 0;
	n = 0;
	ft_build_sp(&sp);
	if (format[j] == 's')
		ft_isspecifier_s(formatp, &sp, a_list);
	else if (format[j] == '%')
		ft_isspecifier_special(formatp, &sp);
	else if (format[j] == 'c')
		ft_isspecifier_c(formatp, &sp, a_list);
	else if (format[j] == 'u' || format[j] == 'x' || format[j] == 'X')
		ft_isspecifier_xu(format, formatp, a_list, &n);
	else if (format[j] == 'p')
		ft_isspecifier_p(formatp, &sp, a_list, &n);
	else
		ft_isspecifier_di(formatp, &sp, a_list, &n);
	*i = *i + j;
	return (sp);
}
