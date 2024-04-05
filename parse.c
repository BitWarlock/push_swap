/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:57:43 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/05 05:57:44 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		swap_a(a);
		exit(EXIT_SUCCESS);
	}
	if (size == 3)
		sort_three(a);
	else if (size > 3)
		sort_five(a, b);
}

void	parse_args(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	fill_stack(ac, av, &stack_a);
	check_dups(stack_a, stack_size(stack_a));
	stack_sorted(stack_a);
	sort_stack(&stack_a, &stack_b);
	display_list(stack_a, 'a');
	display_list(stack_b, 'b');
	free_stack(&stack_a, &stack_b);
}

void	fill_stack(int ac, char *av[], t_stack **a)
{
	char	**strs;
	int		i;
	int		j;
	int		size;
	int		tmp;

	i = 1;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		size = ft_count_tokens(av[i], ' ');
		j = 0;
		while (j < size)
		{
			tmp = ft_atoi(strs[j]);
			if (tmp == -1)
				print_error();
			add_to_stack(a, tmp);
			j++;
		}
		free_split(strs);
		i++;
	}
}

int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == '-'
				|| argv[i][j + 1] == '+'))
				return (0);
			else if (ft_isdigit(argv[i][j]) || argv[i][j] == ' '
				|| argv[i][j] == '\t' || argv[i][j] == '-'
				|| argv[i][j] == '+')
				j++;
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	check_dups(t_stack *stack, int size)
{
	t_stack	*curr;
	t_stack	*cmp;

	curr = stack;
	while (curr->next != stack)
	{
		cmp = curr->next;
		while (cmp != stack)
		{
			if (curr->data == cmp->data)
				print_error();
			cmp = cmp->next;
		}
		curr = curr->next;
	}
	cmp = stack->next;
	while (cmp != curr)
	{
		if (curr->data == cmp->data)
			print_error();
		cmp = cmp->next;
	}
}
