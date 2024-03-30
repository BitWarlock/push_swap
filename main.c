/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:22:53 by mrezki            #+#    #+#             */
/*   Updated: 2024/03/29 22:22:58 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_error(void)
{
	ft_printf(2, "Error\n");
	exit(EXIT_FAILURE);
}

int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == ' '
				|| argv[i][j] == '\t' || argv[i][j] == '-'
				|| argv[i][j] == '+')
				j++;
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	parse_args(int ac, char *av[])
{
	// t_stack	stack_a;
	char	**strs;
	int	i;
	int	j;
	int	size;
	int	tmp;

	i = 1;
	// init_stack(&stack_a);
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		size = ft_count_tokens(av[i], ' ');
		j = 0;
		while (j < size)
		{
			tmp = ft_atoi(strs[j]);
			if (tmp == 0)
				print_error();
			printf("%d\n", tmp);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		print_error();
	if (!check_args(argc, argv))
		print_error();
	parse_args(argc, argv);
	return (EXIT_SUCCESS);
}
