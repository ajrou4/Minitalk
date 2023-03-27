# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majrou <majrou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 03:47:01 by majrou            #+#    #+#              #
#    Updated: 2023/03/27 03:47:02 by majrou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CL_NAME = client
SV_NAME = server
CLBONUS_NAME = client_bonus
SVBONUS_NAME = server_bonus
CL_SRCS = client.c
SV_SRCS = server.c
HEADER = minitalk.h
CLBONUS_SRCS = client_bonus.c
SVBONUS_SRCS = server_bonus.c
CL_OBJS = $(CL_SRCS:.c=.o)
SV_OBJS = $(SV_SRCS:.c=.o)
CLBONUS_OBJS = $(CLBONUS_SRCS:.c=.o)
SVBONUS_OBJS = $(SVBONUS_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBF = ft_printf/libftprintf.a

all: $(CL_NAME) $(SV_NAME) $(SVBONUS_NAME) $(CLBONUS_NAME)

$(CL_NAME): $(CL_OBJS)
	$(CC) $(CFLAGS) $(CL_OBJS) -o $(CL_NAME)

$(SV_NAME): $(SV_OBJS) $(LIBF)
	$(CC) $(CFLAGS) $^ -o $@

$(SVBONUS_NAME): $(SVBONUS_OBJS) $(LIBF)
	$(CC) $(CFLAGS) $^ -o $@

$(CLBONUS_NAME): $(CLBONUS_OBJS)
	$(CC) $(CFLAGS) $(CLBONUS_OBJS) -o $(CLBONUS_NAME)

$(LIBF):
	$(MAKE) -C ./ft_printf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLBONUS_OBJS) $(SVBONUS_OBJS) $(CL_OBJS) $(SV_OBJS)

fclean: clean
	rm -f $(CL_NAME) $(SV_NAME) $(SVBONUS_NAME) $(CLBONUS_NAME)
	$(MAKE) fclean -C ./ft_printf

re: fclean all
