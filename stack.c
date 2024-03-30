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

void	display_list(t_stack *stack)
{
	t_stack *tmp;
	int	i;

	i = 1;
	tmp = stack;
	if (!tmp)
		exit(0);
	else
	{
		printf("Stack: \n");
		while (1)
		{
			printf("%d: %d.\n", i, stack->data);
			if (stack->next == tmp)
				break ;
			stack = stack->next;
			i++;
		}
	}
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
