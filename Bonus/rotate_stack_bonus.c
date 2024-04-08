/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:08:08 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/07 22:57:14 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*rotate_a(t_stack **a)
{
	if (!(*a))
		return (NULL);
	if (*a == (*a)->next)
		return (*a);
	return ((*a)->next);
}

t_stack	*rotate_b(t_stack **a)
{
	if (!(*a))
		return (NULL);
	if (*a == (*a)->next)
		return (*a);
	return ((*a)->next);
}

static t_stack	*silent_rotate(t_stack **a)
{
	if (*a == (*a)->next)
		return (*a);
	return ((*a)->next);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	if (!(*a) && !(*b))
		return ;
	if ((*a))
		(*a) = silent_rotate(a);
	if ((*b))
		(*b) = silent_rotate(b);
}
