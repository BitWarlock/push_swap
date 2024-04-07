/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:22:53 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/05 05:12:02 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	display_list(t_stack *stack, char c)
{
	t_stack	*tmp;
	int		size;

	size = stack_size(stack);
	tmp = stack;
	if (!tmp)
		return ;
	else
	{
		if (c == 'a')
			printf("Stack a Top\n");
		else if (c == 'b')
			printf("Stack b Top\n");
		while (1)
		{
			printf("\t%0d\n", stack->data);
			if (stack->next == tmp)
				break ;
			stack = stack->next;
			size--;
		}
		ft_putchar_fd('\n', 1);
	}
}

void	f(void){system("leaks push_swap");};
int	main(int argc, char *argv[])
{
	atexit(f);
	if (argc < 2)
		return (1);
	if (!argv[1][0])
		print_error();
	if (!check_args(argc, argv))
		print_error();
	parse_args(argc, argv);
	return (EXIT_SUCCESS);
}
