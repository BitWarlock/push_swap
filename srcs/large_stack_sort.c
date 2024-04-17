/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:30:56 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/15 13:54:05 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_stack(t_stack **a, t_stack **b)
{
	int	chunk_size;

	index_stack(*a);
	if (stack_size(*a) > 100)
		chunk_size = stack_size(*a) / 16;
	else
		chunk_size = stack_size(*a) / 7;
	push_to_b(a, b, &chunk_size);
	index_stack(*b);
	push_to_a(a, b);
}

int	max_bits(int i)
{
	int	size;

	size = 0;
	while ((i >> size) != 0)
		size++;
	return (size);
}

void	push_to_b(t_stack **a, t_stack **b, int *chunk_size)
{
	(void)chunk_size;
	int	i;
	int	j;
	int	max;
	int	size;

	max = max_bits(max_in_stack(*a));
	size = stack_size(*a);
	i = 0;
	while (i < max)
	{
		j = 1;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				(*a) = rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		i++;
	}
}

int	num_top(t_stack *a, int count)
{
	t_stack	*head;
	int		i;

	head = a;
	i = 1;
	while (1)
	{
		if (a->index == count)
			break ;
		i++;
		a = a->next;
		if (a == head)
			break ;
	}
	if (i <= stack_size(a) / 2)
		return (1);
	return (0);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	count;

	count = stack_size(*b);
	while (*b)
	{
		if ((*b)->index == count)
		{
			push_a(a, b);
			count--;
		}
		else if (num_top(*b, count) == 1)
			(*b) = rotate_b(b);
		else
			(*b) = reverse_rb(b);
	}
}

void	index_stack(t_stack *a)
{
	t_stack	*curr;
	t_stack	*cmp;
	int		count;

	curr = a;
	while (curr)
	{
		cmp = a;
		count = 0;
		while (cmp)
		{
			if (cmp->data < curr->data)
				count++;
			cmp = cmp->next;
			if (cmp == a)
				break ;
		}
		curr->index = count + 1;
		curr = curr->next;
		if (curr == a)
			break ;
	}
}
