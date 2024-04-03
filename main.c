/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:22:53 by mrezki            #+#    #+#             */
/*   Updated: 2024/03/31 22:38:40 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
			if (ft_isdigit(argv[i][j]) || argv[i][j] == ' '
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
	int	*arr;
	int	i;
	int	j;
	int	a;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	a = 0;
	arr = malloc(sizeof(int) * size);
	while (1)
	{
		arr[a] = stack->data;
		if (stack->next == tmp)
			break ;
		stack = stack->next;
		a++;
	}
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				print_error();
			}
			j++;
		}
		i++;
	}
	free(arr);
}



int	stack_size(t_stack *a)
{
	t_stack	*tmp;
	int	i;

	if (!a)
		return (0);
	i = 1;
	tmp = a;
	while (a->next != tmp)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	display_list(t_stack *stack, char c)
{
	t_stack		*tmp;
	int		size;

	size = stack_size(stack);
	tmp = stack;
	if (!tmp)
		return ;
	else
	{
		if (c == 'a')
			printf("Stack a Top\n");
		else if (c == 'b')
			printf("Stack b Top\n");
		while (1)
		{
			printf("\t%0d\n", stack->data);
			if (stack->next == tmp)
				break ;
			stack = stack->next;
			size--;
		}
		ft_putchar_fd('\n', 1);
	}
}



void	check_if_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a->next != tmp)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return ;
	}
	exit(EXIT_SUCCESS);
}

int	smallest_in_stack(t_stack *a)
{
	t_stack	*head;
	int	tmp;

	tmp = a->data;
	head = a;
	while (1)
	{
		if (a->next == head)
			break ;
		if (tmp > a->next->data)
			tmp = a->next->data;
		a = a->next;
	}
	return (tmp);
}

// void	sort_three(t_stack **a, t_stack **b)
// {
// 	t_stack	*head;
// 	t_stack	*top;
// 	int	small;
// 	// size_t	big;
//
// 	small = smallest_in_stack(*a);
// }

void	sort_stack(t_stack **a, t_stack **b)
{
	(void)b;
	if (stack_size(*a) == 2)
	{
		swap_a(a);
		exit(EXIT_SUCCESS);
	}
	// if (stack_size(*a) > 2)
		// sort_three(a, b);
}

void	parse_args(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**strs;
	int	i;
	int	j;
	int	size;
	int	tmp;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
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
			add_to_stack(&stack_a, tmp);
			j++;
		}
		free_split(strs);
		i++;
	}
	check_dups(stack_a, stack_size(stack_a));
	// sort 3 and 4: 2 or 3 moves
	// sort 5: less than 12
	// sort 100: < 700
	// sort 500: < 5500
	check_if_sorted(stack_a);
	sort_stack(&stack_a, &stack_b);
	display_list(stack_a, 'a');
	display_list(stack_b, 'b');
	free_stack(&stack_a, &stack_b);
}

void	f(void){system("leaks push_swap");};
int	main(int argc, char *argv[])
{
	// atexit(f);
	if (argc < 2)
		return (1);
	if (!check_args(argc, argv))
		print_error();
	parse_args(argc, argv);
	return (EXIT_SUCCESS);
}
