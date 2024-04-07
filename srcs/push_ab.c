/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:07:57 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/07 22:55:47 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*second;

	ft_printf(1, "pb\n");
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

	ft_printf(1, "pa\n");
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
