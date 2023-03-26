# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majrou <majrou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 01:45:22 by majrou            #+#    #+#              #
#    Updated: 2023/03/26 02:42:05 by majrou           ###   ########.fr        #
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
CLBONUS_OBJS = $(CL_OBJS:%.c=%.o)
SVBONUS_OBJS = $(SV_OBJS:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBF = ft_printf/libftprintf.a

all: $(CL_NAME) $(SV_NAME) $(SVBONUS_NAME) $(CLBONUS_NAME)

$(CL_NAME): $(CL_OBJS)
	$(CC) $(CFLAGS) $(CL_OBJS) -o $(CL_NAME)

$(SV_NAME): $(SV_OBJS) $(LIBF)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBF):
	$(MAKE) -C ./ft_printf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@



bonus : $(OBJBONUS)
		@ar rc $(CL_NAME) $(CL_OBJS) $(SV_OBJS)

clean:
	rm -f $(CLBONUS_OBJS) $(CLBONUS_SRCS) $(SV_OBJS) $(CL_OBJS)

fclean: clean
	rm -f $(CL_NAME) $(SV_NAME)
	$(MAKE) fclean -C ./ft_printf


re: fclean all



