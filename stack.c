/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:27:13 by mrezki            #+#    #+#             */
/*   Updated: 2024/03/04 18:35:59 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *stack;
	while ((*stack)->next != tmp)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	free(*stack);
}

void	add_to_stack(t_stack **stack, int data)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		new->data = data;
	}
	else
	{
		last = (*stack)->prev;
		new->next = *stack;
		new->prev = last;
		(*stack)->prev = new;
		last->next = new;
		new->data = data;
	}
}

void	print_error(void)
{
	ft_printf(2, "Error\n");
	exit(EXIT_FAILURE);
}
