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
#include <stdlib.h>

void	display_index(t_stack *a)
{
	int	i;

	i = 0;
	while (i < stack_size(a))
	{
		printf("%d\t%d\n", (a)->index,  (a)->data);
		(a) = (a)->next;
		i++;
	}
}

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

void	big_top(t_stack **a)
{
	// if (index_number(*a, max_in_stack(*a)) > stack_size(*a) / 2)
	// 	(*a) = r_b(a, max_in_stack(*a));
	// else
	// 	rr_b(a, max_in_stack(*a));
}

void	push_to_b(t_stack **a, t_stack **b, t_chunk **chunk)
{
	t_stack	*head;

	head = (*a);
	while (1)
	{
		if ((*a)->index <= (*chunk)->count)
		{
			push_b(a, b);
			head = (*a);
			(*b) = rotate_b(b);
			(*chunk)->count++;
		}
		else if ((*a)->index <= (*chunk)->count + (*chunk)->size)
		{
			push_b(a, b);
			head = (*a);
			(*chunk)->count++;
		}
		else
		{
			(*a) = rotate_a(a);
			head = (*a);
		}
		if ((*a)->next == head)
			break ;
		(*a) = (*a)->next;
	}
}
int	find_next(t_stack *stack_B, t_chunk *chunks)
{
	int		forward;
	int		back;
	t_stack	*tmp;
	t_stack	*head;

	tmp = stack_B;
	head= stack_B;
	forward = 0;
	back = 0;
	while (1)
	{
		if (stack_B->index == chunks->count || stack_B == head)
			break ;
		stack_B = stack_B->next;
		forward++;
	}
	while (1)
	{
		if (tmp->index == chunks->count || stack_B->next == head)
			break ;
		tmp = tmp->prev;
		back++;
	}
	return (forward < back);
}

void	sorting_back(t_stack **a, t_stack **b, t_chunk *chunks)
{
	t_stack	*head;

	head = (*b);
	while (1)
	{
		if ((*b)->next == head)
			break ;
		if ((*b)->index == chunks->count)
		{
			push_a(a, b);
			head = (*b);
			chunks->count--;
		}
		else if (find_next(*b, chunks))
		{
			(*b) = rotate_b(b);
			head = (*b);
		}
		else
		{
			(*b) = reverse_rb(b);
			head = (*b);
		}
		(*b) = (*b)->next;
	}
}

void	push_to_a(t_stack **a, t_stack **b, t_chunk **chunk)
{
	sorting_back(a, b, *chunk);
}
// {
// 	t_stack	*head;
//
// 	head = (*b);
// 	while (1)
// 	{
// 		if ((*a)->index == (*chunk)->count)
// 		{
// 			push_a(a, b);
// 			head = (*b);
// 			(*chunk)--;
// 		}
// 		else if ()
// 	}
// }

void	sort_large_stack(t_stack **a, t_stack **b)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		print_error();
	index_stack(a);
	chunk->count = 0;
	chunk->size = 15;
	push_to_b(a, b, &chunk);
	push_to_a(a, b, &chunk);
	// display_list(*b, 'b');
	// display_list(*a, 'a');
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

void	index_stack(t_stack **a)
{
	t_stack	*head;
	int		i;
	int		j;
	int		*arr;
	int		index;

	i = 0;
	index = 0;
	head = (*a);
	arr = index_arr(stack_size(*a), *a);
	while (i < stack_size(*a))
	{
		j = 0;
		index = 0;
		while (arr[j])
		{
			if (arr[i] > arr[j])
				index++;
			j++;
		}
		(*a)->index = index;
		if ((*a)->next == head)
			break ;
		(*a) = (*a)->next;
		i++;
	}
}

