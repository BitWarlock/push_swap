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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}			t_stack;
void	display_list(t_stack *stack, char c);

/* Instructions */

t_stack	*rotate_b(t_stack **a);
t_stack	*rotate_a(t_stack **a);
t_stack	*reverse_ra(t_stack **a);
t_stack	*reverse_rb(t_stack **a);
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
void	add_to_stack(t_stack **stack, int data);
void	add_to_top_stack(t_stack **a, int data);
void	print_error(void);
void	stack_sorted(t_stack *a);
void	index_stack(t_stack *a);
void	apply_instructions(t_stack **a);
void	check_line(char *str, t_stack **a, t_stack **b);
int		stack_size(t_stack *a);
int		ft_strcmp(const char *s1, const char *s2);

/* Parse */

void	check_dups(t_stack *stack);
void	parse_args(int ac, char *av[]);
int		check_args(int argc, char *argv[]);
int		check_if_sorted(t_stack *a);

#endif // !PSWAP_H
