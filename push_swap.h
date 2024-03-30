/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:12:52 by mrezki            #+#    #+#             */
/*   Updated: 2024/03/04 16:48:24 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
}			t_stack;

void	print_list(t_list *list);
void	free_split(char **str);
void	init_stack(t_stack *stack_a);

int		check_args(int argc, char *argv[]);

#endif // !PSWAP_H
