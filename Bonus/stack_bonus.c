/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:27:13 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/08 02:04:55 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

	if (!(*stack))
		return ;
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
	if (!new)
		print_error();
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

void	add_to_top_stack(t_stack **a, int data)
{
	t_stack	*new;
	t_stack	*first;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		print_error();
	new->data = data;
	if (!(*a))
	{
		*a = new;
		(new->next = new) && (new->prev = new);
	}
	else
	{
		first = *a;
		last = first->prev;
		new->next = first;
		new->prev = last;
		first->prev = new;
		last->next = new;
		*a = new;
	}
}

void	print_error(void)
{
	ft_printf(2, "Error\n");
	exit(EXIT_FAILURE);
}
