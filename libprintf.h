/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:34:42 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/12/30 12:18:03 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	int	minus;
	int width;
	int zero;
	int preci;
	int preciw;

}				t_flags;
typedef	struct	s_specifier
{
	char *formatp;
	char sign;
	char type;
	char p;
	char special;
	char end;
	char ch;
}				t_specifier;

typedef struct	s_global
{
	int		res;
	va_list a_list;
	t_flags	a_flags;
	int		i;
}				t_global;

char			*c_to_s(char c);
char			*ft_tohexa(unsigned long n, char c);
int				ft_atoi(const char *s);
int				ft_tolower(int c);
int				ft_strlen(char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(long n, int fd);
char			*ft_itoa(long int n);
int				ft_printf(const char *format, ...);
t_flags			ft_checkflag(const char *format, va_list a_list, int *i);
void			ft_buildstruct(t_flags *fg);
int				ft_print(const char *format, t_flags *fg,
				int *i, va_list a_list);
char			*ft_strjoin(char *s1, char *s2);
t_specifier		ft_isspecifier(const char *format, int *i,
				char **formatp, va_list a_list);
void			ft_print_mius(t_specifier *sp, char **formatp, int *diff);
int				ft_print_mzw(t_flags *a_f, char **formatp, t_specifier *sp);
int				ft_print_normal(t_specifier *sp, char **formatp, int *len);
void			ft_print_width(t_specifier *sp, char **formatp, int *diff);
void			ft_print_zero(t_specifier *sp, char **formatp, int *diff);
void			ft_print_minus(t_specifier *sp, char **formatp, int *diff);
char			*ft_strdup(const char *s1);
char			*c_to_s(char c);
void			ft_isspecifier_c(char **formatp, t_specifier *sp,
				va_list a_list);
void			ft_build_sp(t_specifier *sp);
void			ft_isspecifier_xu(const char *format, char **formatp,
				va_list a_list, long *n);
void			ft_isspecifier_s(char **formatp, t_specifier *sp,
				va_list a_list);
void			ft_isspecifier_special(char **formatp, t_specifier *sp);
void			ft_isspecifier_p(char **formatp, t_specifier *sp,
				va_list a_list, long *n);
void			ft_isspecifier_di(char **formatp, t_specifier *sp,
					va_list a_list, long *n);
int				ft_print_precision_num(t_flags *a_f, int *len,
				t_specifier *sp, char **formatp);
void			*ft_memset(void *b, int c, size_t len);
int				preci_valid_help(char **formatp, t_flags *a_f,
				t_specifier *sp, int *len);
void			ft_print_preci_valid(char **formatp, t_flags *a_f,
				t_specifier *sp, int *len);
void			nullch_help(char **formatp, t_flags *a_f, int *diff);
void			ft_print_preci_nullch(char **formatp, t_flags *a_f,
				int *len, t_specifier *sp);
int				zero_help(t_flags *a_f, char **formatp, t_specifier *sp,
				int *diff);
void			ft_print_preci_zero(t_flags *a_f, char **formatp,
				t_specifier *sp, int *len);
#endif
