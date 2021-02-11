/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_preci_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:17:53 by fmehdaou          #+#    #+#             */
/*   Updated: 2020/01/05 15:17:55 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	nullch_help(char **formatp, t_flags *a_f, int *diff)
{
	if (a_f->minus == 1)
	{
		write(1, *formatp, 1);
		while ((*diff)-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (a_f->zero == 1)
	{
		while ((*diff)-- > 0)
			ft_putchar_fd('0', 1);
		write(1, *formatp, 1);
	}
	else
	{
		while ((*diff)-- > 0)
			ft_putchar_fd(' ', 1);
		write(1, *formatp, 1);
	}
}

void	ft_print_preci_nullch(char **formatp, t_flags *a_f,
		int *len, t_specifier *sp)
{
	int diff;

	diff = 0;
	if (sp->end == 'y')
	{
		(*len)++;
		if ((diff = a_f->width) > 0)
		{
			*len = *len + (--diff);
			nullch_help(formatp, a_f, &diff);
		}
		else
			write(1, *formatp, 1);
	}
}

int		zero_help(t_flags *a_f, char **formatp, t_specifier *sp, int *diff)
{
	int len;

	len = 0;
	if (sp->special != '%' && sp->ch != 'c')
	{
		free(*formatp);
		*formatp = ft_strdup("");
	}
	if (a_f->width == 0)
	{
		if (sp->special == '%')
			len = 0;
	}
	else
	{
		len = a_f->width - ft_strlen(*formatp);
		*(diff) = a_f->width - ft_strlen(*formatp);
	}
	return (len);
}

void	ft_print_preci_zero(t_flags *a_f, char **formatp,
		t_specifier *sp, int *len)
{
	int diff;

	diff = 0;
	if (a_f->preciw == 0)
	{
		(*len) += zero_help(a_f, formatp, sp, &diff);
		if (a_f->minus == 1)
			ft_print_minus(sp, formatp, &diff);
		else if (a_f->zero == 1)
			ft_print_zero(sp, formatp, &diff);
		else if (diff >= ft_strlen(*formatp))
			ft_print_width(sp, formatp, &diff);
		else
		{
			if (sp->end == 'y')
				write(1, *formatp, 1);
			else
				ft_putstr_fd(*formatp, 1);
		}
	}
}
