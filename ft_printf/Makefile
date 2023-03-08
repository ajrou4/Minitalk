# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majrou <majrou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 06:30:06 by majrou            #+#    #+#              #
#    Updated: 2022/10/31 04:33:13 by majrou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra  -Werror
CC = gcc
RM = rm -rf
INC = ft_printf.h
SRC = help_printf.c ft_printf.c ft_putadress.c

OBJ = ${SRC:%.c=%.o}

all : $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)

%.o : %.c $(INC)
		gcc -c $(CFLAGS) -c $< -o $@

clean :
		@rm -rf  $(OBJ)

fclean :
		@rm -f $(NAME)

re : fclean all

.PHONY:		all clean fclean re
