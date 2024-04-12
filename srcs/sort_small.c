/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:11:48 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/08 02:05:22 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*last;
	int		max;

	if (check_if_sorted(*a))
		return ;
	last = (*a)->prev;
	max = max_in_stack(*a);
	if (last->data == max)
		swap_a(a);
	else if (max == (*a)->data)
	{
		(*a) = rotate_a(a);
		if (check_if_sorted(*a))
			return ;
		swap_a(a);
	}
	else
	{
		(*a) = reverse_ra(a);
		if (check_if_sorted(*a))
			return ;
		swap_a(a);
	}
}

int	min_in_stack(t_stack *a)
{
	t_stack	*head;
	int		tmp;

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

int	max_in_stack(t_stack *a)
{
	t_stack	*head;
	int		tmp;

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
	free_stack(&a);
	exit(EXIT_SUCCESS);
}
