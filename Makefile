# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 16:49:15 by fmehdaou          #+#    #+#              #
#    Updated: 2019/12/30 12:18:21 by fmehdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_strlen.c \
	   ft_tolower.c \
	   ft_putchar_fd.c  \
	   ft_putstr_fd.c \
	   ft_putnbr_fd.c \
	   ft_printf.c	\
	   ft_tohexa.c \
	   ft_itoa.c \
	   ft_atoi.c \
	   ft_checkflag.c \
	   ft_isdigit.c \
	   ft_buildstruct.c \
	   ft_print.c \
	   ft_strjoin.c \
	   ft_isspecifier.c \
	   ft_print_mzw.c \
	   ft_strdup.c \
	   ft_isspecifier_functions1.c \
	   ft_isspecifier_functions2.c \
	   ft_print_precision_num.c \
	   ft_memset.c \
	   ft_print_preci_str2.c \
	   ft_print_preci_str.c \

OUT =  $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OUT)
	 	@(ar rc $(NAME) $(OUT) ; ranlib $(NAME))

%.o: %.c
	 @gcc $(CFLAGS) -c -o $@ $<

clean:
	@/bin/rm -f *.o

fclean:	clean 
	@/bin/rm -f $(NAME)

re: fclean all
