/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:03:29 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/30 18:12:27 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_print(const char *format, t_flags *a_f, int *i, va_list a_list)
{
	int			j;
	char		*formatp;
	t_specifier sp;
	int			len;

	j = 0;
	len = 0;
	sp = ft_isspecifier(&format[j], i, &formatp, a_list);
	len = ft_print_mzw(a_f, &formatp, &sp);
	if (sp.type == 'n')
		len = ft_print_precision_num(a_f, &len, &sp, &formatp);
	if (sp.type == 'c')
	{
		ft_print_preci_nullch(&formatp, a_f, &len, &sp);
		if (a_f->preci == 1 && a_f->width >= 0 && sp.end != 'y')
		{
			ft_print_preci_zero(a_f, &formatp, &sp, &len);
			ft_print_preci_valid(&formatp, a_f, &sp, &len);
		}
	}
	j++;
	*i = *i + j;
	len += ft_strlen(formatp);
	free(formatp);
	return (len);
}
