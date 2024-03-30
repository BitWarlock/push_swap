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

void	print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while(tmp)
	{
		ft_printf(1, "%d\n", tmp->content);
		tmp = tmp->next;
	}
}
//
// void	init_stack(t_stack *stack_a)
// {
// 	
// }
