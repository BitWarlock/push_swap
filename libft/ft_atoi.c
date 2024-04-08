/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:52:27 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/21 16:48:48 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_vars(long *res, long *tmp, int *sign, int *flag)
{
	*tmp = 0;
	*res = 0;
	*sign = 1;
	*flag = 0;
}

int	ft_atoi(const char *str, int *flag)
{
	long	res;
	long	tmp;
	int		sign;

	init_vars(&res, &tmp, &sign, flag);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		sign = ',' - *(str++);
	while (*str >= '0' && *str <= '9')
	{
		tmp = res * 10 + (*str - '0');
		res = tmp;
		if (sign == -1)
			if (res > 2147483648)
				*flag = 1;
		if (res > INT_MAX)
			*flag = 1;
		str++;
	}
	return (sign * res);
}
// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_atoi("2147483648"));
// 	printf("%d\n", ft_atoi("-2147483649"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", ft_atoi("2147483647"));
// 	printf("%d\n", ft_atoi("-42398"));
// 	printf("%d\n", ft_atoi("4823098"));
//
// 	return EXIT_SUCCESS;
// }
