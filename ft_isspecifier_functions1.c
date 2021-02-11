/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecifier_functions1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:53:00 by fmehdaou          #+#    #+#             */
/*   Updated: 2020/01/03 20:53:02 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_isspecifier_s(char **formatp, t_specifier *sp, va_list a_list)
{
	sp->type = 'c';
	if ((*formatp = va_arg(a_list, char*)) == NULL)
		*formatp = ft_strdup("(null)");
	else
		*formatp = ft_strdup(*formatp);
}

void	ft_isspecifier_special(char **formatp, t_specifier *sp)
{
	sp->type = 'c';
	sp->special = '%';
	*formatp = ft_strdup("%");
}

void	ft_isspecifier_p(char **formatp, t_specifier *sp,
						va_list a_list, long *n)
{
	sp->p = 'p';
	*n = va_arg(a_list, long);
	*formatp = ft_strjoin("0x", ft_tohexa(*n, 'x'));
}

void	ft_isspecifier_di(char **formatp, t_specifier *sp,
						va_list a_list, long *n)
{
	*n = va_arg(a_list, int);
	if (*n < 0)
	{
		sp->sign = '-';
		*n = -(*n);
	}
	*formatp = ft_itoa(*n);
}
