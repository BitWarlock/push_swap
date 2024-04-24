# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 18:01:07 by mrezki            #+#    #+#              #
#    Updated: 2024/04/24 18:13:28 by mrezki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC            = push_swap
PROG		= checker
HEADER		= srcs/push_swap.h
B_HEADER	= Bonus/push_swap_bonus.h
LIBFT           = libft.a
LIB_DIR         = ./libft
RM              = rm -rf
CFLAGS          = -Wall -Wextra -Werror -g

SRCS            = srcs/main.c srcs/stack.c srcs/push_ab.c srcs/rotate_stack.c \
		  srcs/reverse_stack.c srcs/swap_stack.c srcs/sort_small.c \
		  srcs/sort_five.c srcs/parse.c srcs/large_stack_sort.c

B_SRCS		= Bonus/main_bonus.c Bonus/parse_bonus.c Bonus/push_ab_bonus.c \
		  Bonus/reverse_stack_bonus.c Bonus/rotate_stack_bonus.c \
		  Bonus/stack_bonus.c Bonus/checker_bonus.c Bonus/swap_stack_bonus.c \

OBJS            = $(SRCS:.c=.o)

B_OBJS		= $(B_SRCS:.c=.o)

all: $(EXEC)

%.o: %.c $(HEADER) $(B_HEADER)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)
	@mv $(LIB_DIR)/$(LIBFT) .


$(EXEC): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@

$(PROG): $(B_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
 
bonus: $(PROG)

clean:
	@$(RM) $(OBJS) $(B_OBJS)
	@$(MAKE) -C libft/ clean

fclean: clean
	@$(RM) $(LIBFT) $(EXEC) $(PROG) a.out .DS_Store
	@$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: clean bonus
