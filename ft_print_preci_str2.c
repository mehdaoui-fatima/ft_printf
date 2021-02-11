/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_preci_str2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:22:07 by fmehdaou          #+#    #+#             */
/*   Updated: 2020/01/05 15:22:09 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		preci_valid_help(char **formatp, t_flags *a_f,
		t_specifier *sp, int *len)
{
	int index;

	index = 0;
	if ((index = a_f->width - ft_strlen(*formatp)) > 0)
	{
		(*len) += index;
		ft_print_minus(sp, formatp, &index);
	}
	else
		ft_print_normal(sp, formatp, len);
	return (index);
}

void	ft_print_preci_valid(char **formatp, t_flags *a_f,
		t_specifier *sp, int *len)
{
	int index;

	index = 0;
	if (a_f->preciw != 0)
	{
		if (ft_strlen(*formatp) - a_f->preciw > 0)
			(*formatp)[a_f->preciw] = '\0';
		if (a_f->minus == 1)
			index = preci_valid_help(formatp, a_f, sp, len);
		else if (a_f->zero == 1)
		{
			if ((index = a_f->width - ft_strlen(*formatp)) > 0)
				(*len) += index;
			ft_print_zero(sp, formatp, &index);
		}
		else if ((index = a_f->width - ft_strlen(*formatp)) > 0)
		{
			(*len) += index;
			ft_print_width(sp, formatp, &index);
		}
		else
			ft_print_normal(sp, formatp, len);
	}
}
