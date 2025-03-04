# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 15:32:42 by mbelkass          #+#    #+#              #
#    Updated: 2024/11/22 03:43:57 by mbelkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_putchar.c ft_putnbr.c ft_putnbr_hexa.c ft_putpointer.c ft_putstr.c ft_printf.c ft_putnbr_un.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


all: ${NAME}


%.o: %.c  libftprintf.h
	${CC} ${CFLAGS} -c $< -o $@


${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}


clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY : clean