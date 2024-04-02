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

#include "libft/libft.h"
#include "push_swap.h"

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

void	rotate_a(t_stack **a)
{
	*a = (*a)->next;
	ft_printf(1, "ra\n");
}

void	rotate_b(t_stack **a)
{
	*a = (*a)->next;
	ft_printf(1, "rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_printf(1, "rr\n");
}

void	reverse_ra(t_stack **a)
{
	*a = (*a)->prev;
	ft_printf(1, "rra\n");
}

void	reverse_rb(t_stack **a)
{
	*a = (*a)->prev;
	ft_printf(1, "rra\n");
}

void	reverse_rab(t_stack **a, t_stack **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	ft_printf(1, "rrr\n");
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

void	display_list(t_stack *stack)
{
	t_stack		*tmp;
	int		size;

	size = stack_size(stack);
	tmp = stack;
	if (!tmp)
		exit(0);
	else
	{
		printf("Top\n");
		while (1)
		{
			printf("\t%0d\n", stack->data);
			if (stack->next == tmp)
				break ;
			stack = stack->next;
			size--;
		}
	}
}

void	swap_a(t_stack **a)
{
	int		tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	ft_printf(1, "sa\n");
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

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*second;
	t_stack	*head;

	head = (*a);
	last = (*a)->prev;
	second = (*a)->next;
	last->next = second;
	second->prev = last;
	(*a) = second;
	printf("*a: %d\nnext: %d\n del: %d\ntmp: %d\n", (*a)->data, last->data, second->data, head->data);
	add_to_stack(b, head->data);
	free(head);
}

void	parse_args(int ac, char *av[])
{
	t_stack	*stack_a = NULL;
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
			if (tmp == -1)
				print_error();
			add_to_stack(&stack_a, tmp);
			j++;
		}
		free_split(strs);
		i++;
	}
	check_dups(stack_a, stack_size(stack_a));
	check_if_sorted(stack_a);
	// rotate_a(&stack_a);
	// swap_a(&stack_a);
	t_stack *b = NULL;
	push_b(&stack_a, &b);
	// display_list(stack_a);
	// printf("size: %d\n", stack_a->size);
	display_list(stack_a);
	// display_list(b);
	free_stack(&stack_a);
}

void	f(void){system("leaks push_swap");};
int	main(int argc, char *argv[])
{
	atexit(f);
	if (argc < 2)
		return (1);
	if (!check_args(argc, argv))
		print_error();
	parse_args(argc, argv);
	return (EXIT_SUCCESS);
}
