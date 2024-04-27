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
	@echo "\033[1;33m"
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)
	mv $(LIB_DIR)/$(LIBFT) .


$(EXEC): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "\n\n\033[1;36mDone."

$(PROG): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "\n\n\033[1;36mDone."
 
bonus: $(PROG)

clean:
	@echo "\033[1;31m"
	$(RM) $(OBJS) $(B_OBJS)
	$(MAKE) -C libft/ clean
	@echo "\n\033[1;31mCleanup Completed.\n"

fclean: clean
	$(RM) $(LIBFT) $(EXEC) $(PROG) a.out .DS_Store
	$(MAKE) -C libft/ fclean
	@echo "\n\033[1;31mFull Cleanup Completed.\n"

re: fclean all

.PHONY: clean bonus
