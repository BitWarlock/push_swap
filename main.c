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



int	check_if_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a->next != tmp)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

void	stack_sorted(t_stack *a)
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

int	max_in_stack(t_stack *a)
{
	t_stack	*head;
	int	tmp;

	if (!a)
		return (0);
	head = a;
	tmp = a->data;
	while (1)
	{
		if (head == a->next)
			break ;
		if (tmp < a->next->data)
			tmp = a->next->data;
		a = a->next;
	}
	return (tmp);
}

int	min_in_stack(t_stack *a)
{
	t_stack	*head;
	int	tmp;

	if (!a)
		return (0);
	head = a;
	tmp = a->data;
	while (1)
	{
		if (head == a->next)
			break ;
		if (tmp > a->next->data)
			tmp = a->next->data;
		a = a->next;
	}
	return (tmp);
}

void	sort_three(t_stack **a)
{
	t_stack	*last;
	int	max;
	int	min;

	min = min_in_stack(*a);
	last = (*a)->prev;
	max = max_in_stack(*a);
	if (last->data == max)
		swap_a(a);
	else if (max == (*a)->data)
	{
		rotate_a(a);
		if (check_if_sorted(*a))
			return ;
		swap_a(a);
	}
	else
	{
		reverse_ra(a);
		if (check_if_sorted(*a))
			return ;
		swap_a(a);
	}
}

// void	add_target(t_stack **a, t_stack **b)
// {
// 	int	target;
// 	t_stack	*a_head;
// 	t_stack	*b_head;
//
// 	a_head = *a;
// 	b_head = *b;
// 	target = b_head->data;
// 	while ((*b)->next != b_head)
// 	{
// 		*a = a_head;
// 		while ((*a)->next != a_head)
// 		{
// 			if ()
// 		}
//
// 	}
// }
//
void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*head;

	push_b(a, b);
	push_b(a, b);
	sort_three(a);
	head = (*a);
	if ((*b)->data > (*a)->prev->data)
	{
		push_b(a, b);
		rotate_a(a);
	}
	else if ((*b)->data < (*a)->data)
		push_b(a, b);
	else if ((*b)->data < (*a)->data && (*b)->data > (*a)->next->data)
	{
		push_b(a, b);
		swap_a(a);
	}
	else {
		reverse_ra(a);
		reverse_ra(a);
		push_a(a, b);
		reverse_ra(a);
	}
}

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
	else if (size == 5)
		sort_five(a, b);
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
	stack_sorted(stack_a);
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
