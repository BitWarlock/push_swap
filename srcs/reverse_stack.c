/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:10:56 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/24 18:13:11 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*reverse_ra(t_stack **a)
{
	if (!(*a))
		return (NULL);
	if (*a == (*a)->next)
		return (*a);
	ft_printf(1, "rra\n");
	return ((*a)->prev);
}

t_stack	*reverse_rb(t_stack **a)
{
	if (!(*a))
		return (NULL);
	if (*a == (*a)->next)
		return (*a);
	ft_printf(1, "rrb\n");
	return ((*a)->prev);
}

t_stack	*silent_rotate(t_stack **a)
{
	if (*a == (*a)->next)
		return (*a);
	return ((*a)->prev);
}

void	reverse_rab(t_stack **a, t_stack **b)
{
	if (!(*a) && !(*b))
		return ;
	if ((*a))
		(*a) = silent_rotate(a);
	if ((*b))
		(*b) = silent_rotate(b);
	ft_printf(1, "rrr\n");
}
