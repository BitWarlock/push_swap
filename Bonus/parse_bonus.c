/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:57:43 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/24 18:12:39 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_if_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (a->next != tmp)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

void	init_vars(long *res, long *tmp, int *sign)
{
	*tmp = 0;
	*res = 0;
	*sign = 1;
}

int	check_if_zero(const char *str)
{
	if ((str[0] == '-' || str[0] == '+'))
		str++;
	while (*str == ' ' || *str == '0' || *str == '\t')
		str++;
	return (*str == '\0');
}

int	_atoi(const char *str, t_stack **a)
{
	long	res;
	long	tmp;
	int		sign;

	init_vars(&res, &tmp, &sign);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (check_if_zero(str))
		return (0);
	if (*str == '-' || *str == '+')
		sign = ',' - *(str++);
	while (*str)
	{
		tmp = res * 10 + (*str - '0');
		res = tmp;
		if ((sign == -1 && res > 2147483648)
			|| (sign == 1 && res > INT_MAX)
			|| *str < '0' || *str > '9')
			print_error(a);
		str++;
	}
	if (res == 0)
		print_error(a);
	return (sign * res);
}

void	check_dups(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*cmp;

	curr = stack;
	while (curr->next != stack)
	{
		cmp = curr->next;
		while (cmp != stack)
		{
			if (curr->data == cmp->data)
				print_error(&stack);
			cmp = cmp->next;
		}
		curr = curr->next;
	}
}
