/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:22:53 by mrezki            #+#    #+#             */
/*   Updated: 2024/03/29 22:22:58 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_error(void)
{
	ft_printf(2, "Error\n");
	exit(EXIT_FAILURE);
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

void	add_to_stack(t_stack **stack, int data)
{
	static int	count;
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (count == 0)
	{
		*stack = new;
		new->next = *stack;
		new->prev = *stack;
		count = 1;
		(*stack)->size = 1;
		new->data = data;
	}
	else
	{
		tmp = (*stack)->prev;
		tmp->next = new;
		new->prev = tmp;
		new->next = *stack;
		tmp = *stack;
		tmp->prev = new;
		new->size += 1;
		(*stack)->size++;
		new->data = data;
		count++;
	}
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

void	parse_args(int ac, char *av[])
{
	t_stack	*stack_a;
	char	**strs;
	int	i;
	int	j;
	int	size;
	int	tmp;

	i = 1;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		size = ft_count_tokens(av[i], ' ');
		j = 0;
		while (j < size)
		{
			tmp = ft_atoi(strs[j]);
			if (tmp == 0)
				print_error();
			add_to_stack(&stack_a, tmp);
			j++;
		}
		free_split(strs);
		i++;
	}
	check_dups(stack_a, stack_a->size);	
	display_list(stack_a);
	printf("size: %d\n", stack_a->size);
	free_stack(&stack_a);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	if (!check_args(argc, argv))
		print_error();
	parse_args(argc, argv);
	return (EXIT_SUCCESS);
}
