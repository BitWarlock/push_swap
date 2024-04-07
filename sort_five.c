/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:52:43 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/05 05:52:44 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	small_top(a, min_in_stack(*a));
	push_b(a, b);
	small_top(a, min_in_stack(*a));
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}

int	index_min(t_stack *a)
{
	t_stack	*head;
	int		i;

	head = a;
	i = 0;
	while (1)
	{
		if (a->next == head || a->data == min_in_stack(a))
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

void	small_top(t_stack **a, int min)
{
	if (index_min(*a) < 2)
		r_a(a, min_in_stack(*a));
	else if (index_min(*a) > 2)
		rr_a(a, min_in_stack(*a));
	else
	{
		*a = rotate_a(a);
		*a = rotate_a(a);
	}
}

t_stack	*r_a(t_stack **a, int min)
{
	t_stack	*head;

	head = (*a);
	while ((*a)->next != head)
	{
		if ((*a)->data == min)
			break ;
		(*a) = rotate_a(a);
	}
	return (*a);
}

t_stack	*rr_a(t_stack **a, int min)
{
	t_stack	*head;

	head = (*a);
	while ((*a)->prev != head)
	{
		if ((*a)->data == min)
			break ;
		(*a) = reverse_ra(a);
	}
	return (*a);
}

t_stack	*r_b(t_stack **b, int min)
{
	t_stack	*head;

	head = (*b);
	while ((*b)->next != head)
	{
		if ((*b)->data == min)
			break ;
		(*b) = rotate_b(b);
	}
	return (*b);
}

t_stack	*rr_b(t_stack **b, int min)
{
	t_stack	*head;

	head = (*b);
	while ((*b)->prev != head)
	{
		if ((*b)->data == min)
			break ;
		(*b) = reverse_rb(b);
	}
	return (*b);
}