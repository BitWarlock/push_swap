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

int	index_number(t_stack *a, int number)
{
	t_stack	*head;
	int		i;

	head = a;
	i = 0;
	while (1)
	{
		if (a->next == head || a->data == number)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

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
	int	i;
	t_stack	*head;

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
	if (i < stack_size(a) / 2)
		return (1);
	return (0);
}

void	push_to_a(t_stack **a, t_stack **b, t_chunk *chunk)
{
	t_stack	*head;

	head = (*b)->next;
	while (*b)
	{
		if ((*b)->index == chunk->count)
		{
			push_a(a, b);
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
	chunk->size = 15;
	if (stack_size(*a) > 100)
		chunk->size += 15;
	push_to_b(a, b, chunk);
	index_stack(*b);
	push_to_a(a, b, chunk);
	free(chunk);
}

int	*index_arr(int size, t_stack *a)
{
	t_stack	*head;
	int		*arr;
	int		i;

	head = (a);
	i = 0;
	arr = malloc(sizeof(int) * stack_size(a));
	if (!arr)
		print_error();
	while ((a)->next != head)
	{
		arr[i] = (a)->data;
		(a) = (a)->next;
		i++;
	}
	arr[i] = (a)->data;
	return (arr);
}

void	index_stack(t_stack *a)
{
	t_stack	*head;
	int		i;
	int		j;
	int		*arr;
	int		index;

	i = 0;
	index = 1;
	head = (a);
	arr = index_arr(stack_size(a), a);
	while (i < stack_size(a))
	{
		j = 0;
		index = 1;
		while (arr[j])
		{
			if (arr[i] > arr[j])
				index++;
			j++;
		}
		(a)->index = index;
		if ((a)->next == head)
			break ;
		(a) = (a)->next;
		i++;
	}
}

