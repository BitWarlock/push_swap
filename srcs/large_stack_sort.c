/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:30:56 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/08 02:05:02 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_stack(t_stack **a, t_stack **b)
{
	int	count;
	int	chunk_size;

	index_stack(*a);
	count = 0;
	if (stack_size(*a) > 100)
		chunk_size = 41;
	else
		chunk_size = 17;
	push_to_b(a, b, &count, &chunk_size);
	index_stack(*b);
	push_to_a(a, b, &count);
}

void	push_to_b(t_stack **a, t_stack **b, int *count, int *chunk_size)
{
	while (*a)
	{
		if ((*a)->index <= (*count))
		{
			push_b(a, b);
			(*b) = rotate_b(b);
			(*count)++;
			(*chunk_size)++;
		}
		else if ((*a)->index <= (*chunk_size))
		{
			push_b(a, b);
			(*count)++;
			(*chunk_size)++;
		}
		else
			(*a) = rotate_a(a);
	}
}

int	num_top(t_stack *a, int *count)
{
	t_stack	*head;
	int		i;

	head = a;
	i = 1;
	while (1)
	{
		if (a->index == (*count))
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

void	push_to_a(t_stack **a, t_stack **b, int *count)
{
	while (*b)
	{
		if ((*b)->index == (*count))
		{
			push_a(a, b);
			(*count)--;
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
