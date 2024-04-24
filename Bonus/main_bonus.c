/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:22:53 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/24 18:12:37 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	empty_string(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			return (1);
		if (!av[i][0] || ((av[i][0] == '-' || av[i][0] == '+')
			&& av[i][1] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

void	free_all(char *str, t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	free(str);
	ft_printf(2, "Error\n");
	exit(EXIT_FAILURE);
}

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

void	parse_args(int ac, char *av[], t_stack **stack_a)
{
	char	**strs;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	*stack_a = NULL;
	while (++i < ac)
	{
		strs = ft_split(av[i], ' ');
		j = -1;
		while (++j < ft_count_tokens(av[i], ' '))
		{
			tmp = _atoi(strs[j], stack_a);
			add_to_stack(stack_a, tmp);
		}
		free_split(strs);
	}
	apply_instructions(stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc < 2)
		return (1);
	if (empty_string(argc, argv))
		print_error(NULL);
	parse_args(argc, argv, &stack_a);
	return (EXIT_SUCCESS);
}
