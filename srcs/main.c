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

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	if (!argv[1][0])
		print_error();
	if (!check_args(argc, argv))
		print_error();
	parse_args(argc, argv);
	return (EXIT_SUCCESS);
}
