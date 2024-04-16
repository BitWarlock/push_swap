/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:41:00 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/15 13:55:02 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a(t_stack **a)
{
	int		tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
}

void	swap_b(t_stack **a)
{
	int		tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
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
}
