/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:56:55 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/07 22:56:56 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	apply_instructions(t_stack **a)
{
	char	*str;
	t_stack	*b;

	b = NULL;
	str = get_next_line(0);
	while (str)
	{
		check_line(str, a, &b);
		free(str);
		str = get_next_line(0);
	}
	if (check_if_sorted(*a))
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
}

void	check_line(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "ra\n") == 0)
		(*a) = rotate_a(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		(*b) = rotate_b(b);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap_a(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_b(b);
	else if (ft_strcmp(str, "ss\n") == 0)
		swap_ab(a, b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate_ab(a, b);
	else if (ft_strcmp(str, "rrb\n") == 0)
		(*b) = reverse_rb(b);
	else if (ft_strcmp(str, "rra\n") == 0)
		(*a) = reverse_ra(a);
	else if (ft_strcmp(str, "rrr\n") == 0)
		reverse_rab(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push_b(a, b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push_a(a, b);
	else
		print_error();
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	stack_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a->next != tmp)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return ;
	}
	exit(EXIT_SUCCESS);
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
