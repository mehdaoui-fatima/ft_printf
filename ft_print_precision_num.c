/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision_num.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:21:52 by fmehdaou          #+#    #+#             */
/*   Updated: 2020/01/04 15:21:54 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void	ft_print_preci_vall(t_flags *a_f, t_specifier *sp,
	char **formatp, int *diff)
{
	int v1;

	v1 = 0;
	v1 = a_f->preciw - ft_strlen(*formatp);
	(*diff) -= v1;
	while ((*diff)-- > 0 && a_f->minus == 0)
		ft_putchar_fd(' ', 1);
	ft_print_zero(sp, formatp, &v1);
	while ((*diff)-- >= 0 && a_f->minus == 1)
		ft_putchar_fd(' ', 1);
}

static int	ft_print_preci_mz(t_flags *a_f, t_specifier *sp,
	char **formatp, int *diff)
{
	int len;

	len = 0;
	if (a_f->minus == 1)
		ft_print_minus(sp, formatp, diff);
	else
	{
		if (sp->p == 'p')
		{
			*formatp = ft_strdup("0x");
			(*diff)++;
			len++;
		}
		ft_print_width(sp, formatp, diff);
	}
	return (len);
}

static void	ft_print_precision_num_validated(t_flags *a_f, t_specifier *sp,
	char **formatp, int *len)
{
	int diff;

	diff = 0;
	diff = a_f->width - ft_strlen(*formatp);
	if (sp->sign == '-')
	{
		diff--;
		if ((a_f->width - a_f->preciw) <= 0)
			(*len)++;
	}
	if (a_f->preciw - ft_strlen(*formatp) > 0)
		ft_print_preci_vall(a_f, sp, formatp, &diff);
	else
		(*len) += ft_print_preci_mz(a_f, sp, formatp, &diff);
}

static void	ft_allarezeros(t_flags *a_f, int *len, t_specifier *sp,
	char **formatp)
{
	int max;

	max = 0;
	if (sp->sign == '-')
		(*len)++;
	if (a_f->width > a_f->preciw)
		max = a_f->width;
	else
		max = a_f->preciw;
	if ((*len = max - ft_strlen(*formatp)) <= 0)
	{
		*len = 0;
		if (sp->sign == '-')
			(*len)++;
	}
	if (**formatp == '0' && a_f->preciw == 0 && sp->p != 'p')
	{
		**formatp = '\0';
		*len += (a_f->width > 0) ? 1 : 0;
	}
}

int			ft_print_precision_num(t_flags *a_f, int *len, t_specifier *sp,
	char **formatp)
{
	int diff;
	int v1;

	diff = 0;
	v1 = 0;
	if (a_f->width >= 0 && a_f->preci == 1)
	{
		ft_allarezeros(a_f, len, sp, formatp);
		if (a_f->width - ft_strlen(*formatp) > 0)
			ft_print_precision_num_validated(a_f, sp, formatp, len);
		else if ((v1 = a_f->preciw - ft_strlen(*formatp)) > 0)
		{
			if (sp->sign == '-')
				(*len)++;
			ft_print_zero(sp, formatp, &v1);
		}
		else
		{
			if (sp->sign == '-')
				ft_putchar_fd('-', 1);
			ft_putstr_fd(*formatp, 1);
		}
	}
	return (*len);
}
