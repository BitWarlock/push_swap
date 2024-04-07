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
PROG		= checker
HEADER		= srcs/push_swap.h
LIBFT           = libft.a
LIB_DIR         = ./libft
RM              = rm -rf
CFLAGS          = -Wall -Wextra -Werror
# CFLAGS		= -g

SRCS            = srcs/main.c srcs/stack.c srcs/push_ab.c srcs/rotate_stack.c \
		  srcs/reverse_stack.c srcs/swap_stack.c srcs/sort_small.c \
		  srcs/sort_five.c srcs/parse.c srcs/large_stack_sort.c

B_SRCS		= Bonus/main.c Bonus/parse.c Bonus/push_ab.c \
		  Bonus/reverse_stack.c Bonus/rotate_stack.c \
		  Bonus/stack.c Bonus/checker.c

OBJS            = $(SRCS:.c=.o)

B_OBJS		= $(B_SRCS:.c=.o)

all: $(EXEC)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)
	mv $(LIB_DIR)/$(LIBFT) .


$(EXEC):  $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $^ -o $(PROG)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(LIBFT) $(EXEC) $(PROG) a.out .DS_Store
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: clean bonus
