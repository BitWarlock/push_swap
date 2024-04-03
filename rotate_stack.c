/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:08:08 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/03 01:08:09 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	if (*a == (*a)->next)
		return ;
	*a = (*a)->next;
	ft_printf(1, "ra\n");
}

void	rotate_b(t_stack **a)
{
	if (*a == (*a)->next)
		return ;
	*a = (*a)->next;
	ft_printf(1, "rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	if (*a == (*a)->next)
		return ;
	if (*b == (*b)->next)
		return ;
	*a = (*a)->next;
	*b = (*b)->next;
	ft_printf(1, "rr\n");
}