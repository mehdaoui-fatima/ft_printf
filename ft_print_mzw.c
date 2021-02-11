/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mzw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:22:46 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/30 14:35:15 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_print_minus(t_specifier *sp, char **formatp, int *diff)
{
	if (sp->sign == '-')
		ft_putchar_fd('-', 1);
	ft_putstr_fd(*formatp, 1);
	while ((*diff)-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_print_zero(t_specifier *sp, char **formatp, int *diff)
{
	if (sp->sign == '-')
		ft_putchar_fd('-', 1);
	while ((*diff)-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(*formatp, 1);
}

void	ft_print_width(t_specifier *sp, char **formatp, int *diff)
{
	while ((*diff)-- > 0)
		ft_putchar_fd(' ', 1);
	if (sp->sign == '-')
		ft_putchar_fd('-', 1);
	ft_putstr_fd(*formatp, 1);
}

int		ft_print_normal(t_specifier *sp, char **formatp, int *len)
{
	if (sp->sign == '-')
	{
		ft_putchar_fd('-', 1);
		(*len)++;
	}
	ft_putstr_fd(*formatp, 1);
	return (*len);
}

int		ft_print_mzw(t_flags *a_f, char **formatp, t_specifier *sp)
{
	int len;
	int diff;

	len = 0;
	diff = 0;
	if (a_f->preci == -1 && sp->end != 'y')
	{
		if (a_f->width > 0 && ((diff = a_f->width - ft_strlen(*formatp)) > 0))
		{
			len += diff;
			if (sp->sign == '-')
				diff--;
			if (a_f->minus == 1)
				ft_print_minus(sp, formatp, &diff);
			else if (a_f->zero == 1)
				ft_print_zero(sp, formatp, &diff);
			else
				ft_print_width(sp, formatp, &diff);
		}
		else
			ft_print_normal(sp, formatp, &len);
	}
	return (len);
}
