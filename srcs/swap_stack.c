/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:41:00 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/08 02:05:28 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	int		tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	ft_printf(1, "sa\n");
}

void	swap_b(t_stack **a)
{
	int		tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	ft_printf(1, "sb\n");
}

void	swap_ab(t_stack **a, t_stack **b)
{
	int	tmp;

	if (stack_size(*a) < 2 && stack_size(*b) < 2)
		return ;
	if (stack_size(*a) > 2)
	{
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
	}
	if (stack_size(*b) > 2)
	{
		tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
	}
	ft_printf(1, "ss\n");
}

int	stack_size(t_stack *a)
{
	t_stack	*tmp;
	int		i;

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
