/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:10:56 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/03 01:10:57 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_ra(t_stack **a)
{
	if (*a == (*a)->next)
		return ;
	*a = (*a)->prev;
	ft_printf(1, "rra\n");
}

void	reverse_rb(t_stack **a)
{
	if (*a == (*a)->next)
		return ;
	*a = (*a)->prev;
	ft_printf(1, "rrb\n");
}

void	reverse_rab(t_stack **a, t_stack **b)
{
	if (*a == (*a)->next)
		return ;
	if (*b == (*b)->next)
		return ;
	*a = (*a)->prev;
	*b = (*b)->prev;
	ft_printf(1, "rrr\n");
}
