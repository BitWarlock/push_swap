/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:12:52 by mrezki            #+#    #+#             */
/*   Updated: 2024/03/31 05:06:00 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}			t_stack;

void	free_split(char **str);
void	free_stack(t_stack **stack);
void	init_stack(t_stack *stack_a);
void	display_list(t_stack *stack);
void	add_to_stack(t_stack **stack, int data);
void	print_error(void);

int		check_args(int argc, char *argv[]);

#endif // !PSWAP_H
