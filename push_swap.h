/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:12:52 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/05 05:12:13 by mrezki           ###   ########.fr       */
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
	int				index;
}			t_stack;

typedef struct s_chunk
{
	int	count;
	int	size;
}			t_chunk;

/* Instructions */

t_stack	*rotate_b(t_stack **a);
t_stack	*rotate_a(t_stack **a);
t_stack	*reverse_ra(t_stack **a);
t_stack	*reverse_rb(t_stack **a);
t_stack	*r_a(t_stack **a, int min);
t_stack	*rr_a(t_stack **a, int min);
t_stack	*r_b(t_stack **a, int min);
t_stack	*rr_b(t_stack **a, int min);
void	rotate_ab(t_stack **a, t_stack **b);
void	reverse_rab(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	swap_ab(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **a);

/* Stack Utils */

void	free_split(char **str);
void	free_stack(t_stack **stack);
void	init_stack(t_stack *stack_a);
void	add_to_stack(t_stack **stack, int data);
void	add_to_top_stack(t_stack **a, int data);
void	print_error(void);
void	stack_sorted(t_stack *a);
void	small_top(t_stack **a, int min);
void	fill_stack(int ac, char *av[], t_stack **a);
void	index_stack(t_stack **a);
int		min_in_stack(t_stack *a);
int		stack_size(t_stack *a);
int		index_min(t_stack *a);
int		max_in_stack(t_stack *a);

/* Parse */

void	check_dups(t_stack *stack, int size);
void	parse_args(int ac, char *av[]);
int		check_args(int argc, char *argv[]);
int		check_if_sorted(t_stack *a);

/* Sort */

void	sort_large_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a);

void	display_list(t_stack *stack, char a);

#endif // !PSWAP_H
