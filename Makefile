# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcruz-y- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 16:10:03 by jcruz-y-          #+#    #+#              #
#    Updated: 2018/09/18 12:20:46 by jcruz-y-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_putchar.c ft_putnbr.c ft_putstr.c b_printf.c ft_strlen.c

SRCSO = ft_putchar.o ft_putnbr.o ft_putstr.o b_printf.o ft_strlen.o

HEADER = ft.h

$(NAME): 
	gcc -Werror -Wextra -Wall -c $(SRCS) -I=$(HEADER)
	ar rcs $(NAME) $(SRCSO)

all: $(NAME)

clean: 
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
