/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:30:56 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/05 21:30:57 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, t_chunk *chunk)
{
	while (*a)
	{
		if ((*a)->index <= chunk->count)
		{
			push_b(a, b);
			(*b) = rotate_b(b);
			chunk->count++;
		}
		else if ((*a)->index <= chunk->count + chunk->size)
		{
			push_b(a, b);
			chunk->count++;
		}
		else
			(*a) = rotate_a(a);
	}
}

int	num_top(t_stack *a, t_chunk *chunk)
{
	t_stack	*head;
	int		i;

	head = a;
	i = 1;
	while (1)
	{
		if (a->index == chunk->count)
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

void	push_to_a(t_stack **a, t_stack **b, t_chunk *chunk)
{
	t_stack	*head;

	head = (*b);
	while (*b)
	{
		if ((*b)->index == chunk->count)
		{
			push_a(a, b);
			head = (*b);
			chunk->count--;
		}
		else if (num_top(*b, chunk) == 1)
			(*b) = rotate_b(b);
		else
			(*b) = reverse_rb(b);
	}
}

void	sort_large_stack(t_stack **a, t_stack **b)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		print_error();
	index_stack(*a);
	chunk->count = 0;
	chunk->size = 14;
	if (stack_size(*a) > 100)
		chunk->size += 17;
	push_to_b(a, b, chunk);
	index_stack(*b);
	push_to_a(a, b, chunk);
	free(chunk);
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
