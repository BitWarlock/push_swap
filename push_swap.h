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
	int				target;
}			t_stack;

void	display_list(t_stack *stack, char a);
int	stack_size(t_stack *a);

void	free_split(char **str);
void	free_stack(t_stack **stack, t_stack **b);
void	init_stack(t_stack *stack_a);
void	add_to_stack(t_stack **stack, int data);
void	add_to_top_stack(t_stack **a, int data);

void	print_error(void);

void	push_b(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	rotate_ab(t_stack **a, t_stack **b);
void	rotate_b(t_stack **a);
void	rotate_a(t_stack **a);
void	reverse_rab(t_stack **a, t_stack **b);
void	reverse_rb(t_stack **a);
void	reverse_ra(t_stack **a);
void	swap_ab(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **a);

int		check_args(int argc, char *argv[]);

#endif // !PSWAP_H
