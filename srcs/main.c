/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:22:53 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/08 02:05:04 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
