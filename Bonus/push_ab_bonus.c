/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:07:57 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/15 13:54:47 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*second;

	if (*a)
	{
		add_to_top_stack(b, (*a)->data);
		second = (*a)->next;
		last = (*a)->prev;
		free(*a);
		if (second != *a)
		{
			*a = second;
			second->prev = last;
			last->next = second;
		}
		else
			*a = NULL;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*second;

	if (*b)
	{
		add_to_top_stack(a, (*b)->data);
		second = (*b)->next;
		last = (*b)->prev;
		free(*b);
		if (second != *b)
		{
			*b = second;
			second->prev = last;
			last->next = second;
		}
		else
			*b = NULL;
	}
}
