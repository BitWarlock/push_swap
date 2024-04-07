# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrezki <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 18:01:07 by mrezki            #+#    #+#              #
#    Updated: 2024/03/31 22:38:11 by mrezki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC            = push_swap
HEADER		= push_swap.h
LIBFT           = libft.a
LIB_DIR         = ./libft
RM              = rm -rf
# CFLAGS          = -Wall -Wextra -Werror -g
CFLAGS		= -g

SRCS            = main.c stack.c push_ab.c rotate_stack.c reverse_stack.c \
		  swap_stack.c sort_small.c sort_five.c parse.c \
		  large_stack_sort.c

OBJS            = $(SRCS:.c=.o)

all: $(EXEC)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)
	mv $(LIB_DIR)/$(LIBFT) .


$(EXEC):  $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(LIBFT) $(EXEC) a.out .DS_Store
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: clean fclean
