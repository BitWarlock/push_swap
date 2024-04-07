/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:57:43 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/07 22:55:44 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = stack_size(*a);
	if (size == 2)
	{
		swap_a(a);
		exit(EXIT_SUCCESS);
	}
	if (size == 3)
		sort_three(a);
	else if (size < 6)
		sort_five(a, &b);
	else
		sort_large_stack(a, &b);
}

void	parse_args(int ac, char *av[])
{
	t_stack	*stack_a;
	char	**strs;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	stack_a = NULL;
	while (++i < ac)
	{
		strs = ft_split(av[i], ' ');
		j = -1;
		while (++j < ft_count_tokens(av[i], ' '))
		{
			tmp = ft_atoi(strs[j]);
			if (tmp == -1)
				print_error();
			add_to_stack(&stack_a, tmp);
		}
		free_split(strs);
	}
	check_dups(stack_a);
	stack_sorted(stack_a);
	sort_stack(&stack_a);
	free_stack(&stack_a);
}

int	helper(char *str)
{
	if ((str[0] == '+' && str[1] == '+')
		|| (str[0] == '+' && !str[1]))
		return (0);
	return (1);
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
			if (helper(argv[i]) == 0)
				return (0);
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == '-'
				|| argv[i][j + 1] == '+'))
				return (0);
			else if (ft_isdigit(argv[i][j]) || argv[i][j] == ' '
				|| argv[i][j] == '\t' || argv[i][j] == '-'
				|| argv[i][j] == '+')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_dups(t_stack *stack)
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
}
