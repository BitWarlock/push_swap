/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:57:06 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/12 15:30:19 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(char *str, t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	free(str);
	ft_printf(2, "Error\n");
	exit(EXIT_FAILURE);
}

static int	empty_string(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc < 2)
		return (1);
	if (empty_string(argc, argv))
		print_error(NULL);
	if (!check_args(argc, argv))
		print_error(NULL);
	parse_args(argc, argv, &stack_a);
	return (EXIT_SUCCESS);
}
