# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 12:26:42 by rlopez-s          #+#    #+#              #
#    Updated: 2022/01/29 13:02:34 by rlopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

NAME = libft.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

$(OBJS): %o: %c
	$(CC) $(CFLAGS) $(SRCS) -c

clean: 
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re:	fclean all

