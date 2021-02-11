/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:57:19 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/31 13:55:59 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_printf(const char *format, ...)
{
	t_global tg;

	tg.res = 0;
	tg.i = 0;
	va_start(tg.a_list, format);
	while (format[tg.i])
	{
		if (format[tg.i] != '%')
		{
			ft_putchar_fd(format[(tg.i)++], 1);
			tg.res++;
		}
		else
		{
			tg.i++;
			tg.a_flags = ft_checkflag(&format[tg.i], tg.a_list, &(tg.i));
			tg.res += ft_print(&format[tg.i], &tg.a_flags, &tg.i, tg.a_list);
		}
	}
	va_end(tg.a_list);
	return (tg.res);
}
