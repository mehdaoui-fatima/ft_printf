/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:43:33 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/30 14:02:48 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_checkflag_mz(const char *format, int *i, t_flags *fg)
{
	int j;

	j = 0;
	while (format[j] == '-' || format[j] == '0')
	{
		if (format[j] == '-')
			fg->minus = 1;
		else
			fg->zero = 1;
		j++;
	}
	*i = *i + j;
}

void	ft_checkflag_w(const char *format, int *i, t_flags *fg, va_list a_list)
{
	int j;

	j = 0;
	if (format[j] == '*' || ('0' <= format[j] && format[j] <= '9'))
	{
		while (format[j] == '*')
		{
			if ((fg->width = va_arg(a_list, int)) < 0)
			{
				fg->width = -fg->width;
				fg->minus = 1;
			}
			j++;
		}
		if ('0' <= format[j] && format[j] <= '9')
		{
			fg->width = ft_atoi(&format[j]);
			while (format[j] && '0' <= format[j] && format[j] <= '9')
				j++;
		}
	}
	*i = *i + j;
}

void	ft_checkflag_p(const char *format, int *i, t_flags *fg, va_list a_list)
{
	int j;

	j = 0;
	if (format[j] == '.')
	{
		fg->preci = 1;
		j++;
		if (format[j] == '*')
		{
			fg->preciw = va_arg(a_list, int);
			if (fg->preciw < 0 && fg->zero == 1)
			{
				fg->preci = -1;
			}
			j++;
		}
		else
		{
			fg->preciw = ft_atoi(&format[j]);
			while (format[j] && '0' <= format[j] && format[j] <= '9')
				j++;
		}
	}
	*i = *i + j;
}

t_flags	ft_checkflag(const char *format, va_list a_list, int *i)
{
	t_flags fg;
	int		j;

	j = 0;
	ft_buildstruct(&fg);
	ft_checkflag_mz(&format[j], &j, &fg);
	ft_checkflag_w(&format[j], &j, &fg, a_list);
	ft_checkflag_p(&format[j], &j, &fg, a_list);
	*i = *i + j;
	return (fg);
}
