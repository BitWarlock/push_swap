/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:12:32 by mrezki            #+#    #+#             */
/*   Updated: 2024/04/05 05:12:33 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_stack
{
int	data;
int	size;
struct s_stack *next;
struct s_stack *prev;
}		t_stack;

void	create_stack(int arr[], int size, t_stack **stack)
{
t_stack	*new;
t_stack	*tmp;
int	i;

*stack = NULL;
i = 0;
while (i < size)
{
	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = arr[i];
	if (i == 0)
	{
		*stack = new;
		new->next = *stack;
		new->prev = *stack;
		new->size = 1;
		(*stack)->size = 1;
	}
	else
	{
		tmp = (*stack)->prev;
		tmp->next = new;
		new->prev = tmp;
		new->next = *stack;
		tmp = *stack;
		tmp->prev = new;
		new->size += 1;
		(*stack)->size++;
	}
	i++;
}
}

// void	display_list(t_stack *stack)
// {
// 	t_stack		*tmp;
// 	int			i;
//
// 	i = 1;
// 	tmp = stack;
// 	if (!tmp)
// 		exit(0);
// 	else
// 	{
// 		printf("Stack a: \n\n");
// 		while (1)
// 		{
// 			printf("%d\n", stack->prev->data);
// 			if (stack->prev == tmp)
// 				break ;
// 			stack = stack->prev;
// 			i++;
// 		}
// 	}
// }

void	display_list(t_stack *stack)
{
t_stack		*tmp;
int			i;

tmp = stack;
if (!stack)
	printf("Empty stack\n");
else
{
	printf("Stack: \n");
	i = 0;
	while (1)
	{
		printf("%0d:\t%d\n", i, stack->data);
		if (stack->next == tmp)
			break ;
		stack = stack->next;
		i++;
	}
}
}

void	print_stacks(t_stack *a, t_stack *b)
{
t_stack	*atmp;
t_stack	*btmp;
int	i;
int	size;

if (a->size == 0 && b->size == 0)
	printf("Both stacks are Empty.\n");
if (a->size >= b->size)
	size = a->size;
else
	size = b->size;
i = 0;
atmp = a;
btmp = b;
printf("Stack A\n\n");
while (i < size)
{
	a = a->prev;
	printf("%d\t\n", a->data);
	// b = b->next;
	i++;
}
size = b->size;
i = 0;
printf("\nStack B\n\n");
while (i < size)
{
	b = b->prev;
	printf("%d\t\t\n", b->data);
	// b = b->next;
	i++;
}
}

void	free_stack(t_stack **stack)
{
t_stack	*tmp;
t_stack	*next;

tmp = *stack;
while ((*stack)->next != tmp)
{
	next = (*stack)->next;
	free(*stack);
	*stack = next;
}
free(*stack);
}

void	rotate_a(t_stack **a)
{
*a = (*a)->next;
}

void	rotate_b(t_stack **b)
{
*b = (*b)->prev;
}

void	rotate_ab(t_stack **a, t_stack **b)
{
rotate_a(a);
rotate_b(b);
}

void	reverse_ra(t_stack **a)
{
*a = (*a)->next;
}

void	reverse_rb(t_stack **b)
{
*b = (*b)->next;
}

void	reverse_rab(t_stack **a, t_stack **b)
{
reverse_ra(a);
reverse_rb(b);
}

void	swap_a(t_stack **a)
{
t_stack	*last;
t_stack	*s_last;
int		tmp;

if ((*a)->size < 2)
	return ;
last = (*a)->prev;
s_last = (*a)->prev->prev;
tmp = last->data;
last->data = s_last->data;
s_last->data = tmp;
}

void	swap_b(t_stack **b)
{
t_stack	*last;
t_stack	*s_last;
int		tmp;

if ((*b)->size < 2)
	return ;
last = (*b)->prev;
s_last = (*b)->prev->prev;
tmp = last->data;
last->data = s_last->data;
s_last->data = tmp;
}	

void	swap_ab(t_stack **a, t_stack **b)
{
swap_a(a);
swap_b(b);
}

void	add_to_stack(t_stack **stack, int data)
{
static int	count;
t_stack	*new;
t_stack	*tmp;

new = (t_stack *)malloc(sizeof(t_stack));
if (count == 0)
{
	*stack = new;
	new->next = *stack;
	new->prev = *stack;
	count = 1;
	(*stack)->size = 1;
	new->data = data;
}
else
{
	tmp = (*stack)->prev;
	tmp->next = new;
	new->prev = tmp;
	new->next = *stack;
	tmp = *stack;
	tmp->prev = new;
	new->size += 1;
	(*stack)->size++;
	new->data = data;
	count++;
}
}

void	push_b(t_stack **a, t_stack **b)
{
t_stack	*last;
t_stack	*s_last;

if (!(*a))
	return ;
last = (*a)->prev;
s_last = (*a)->prev->prev;
free(last);
(*a)->prev = s_last;
s_last->next = (*a);
add_to_stack(b, last->data);
}

void	push_a(t_stack **a, t_stack **b)
{
t_stack	*last;
t_stack	*s_last;

if (!(*b))
	return ;
last = (*b)->prev;
s_last = (*b)->prev->prev;
free(last);
(*b)->prev = s_last;
s_last->next = (*b);
add_to_stack(a, last->data);
}

// void	push_a(t_stack **a, t_stack **b)
// {
// 	t_stack	*last;
// 	t_stack	*s_last;
//
// 	last = (*b)->prev;
// 	if (!*b)
// 		return ;
// 	s_last = (*b)->prev->prev;
// 	free(*b);
// 	(*b)->prev = s_last;
// 	s_last->next = (*b);
// 	add_to_stack(a, last->data);
// }
//
void	f(void){system("leaks a.out");};

int main(void)
{
// atexit(f);
int	arr[] = {3, 1, 2};
int	size = sizeof(arr) / sizeof(arr[0]);
t_stack	*stack;
t_stack	*b;

create_stack(arr, size, &stack);
// swap_a(&stack);
// push_b(&stack, &b);
// push_b(&stack, &b);
// push_b(&stack, &b);
rotate_a(&stack);
// rotate_b(&b);
// reverse_rab(&stack, &b);
// swap_a(&stack);
// push_a(&stack, &b);
// push_a(&stack, &b);
// push_a(&stack, &b);
// display_list(b);
// print_stacks(stack, b);
display_list(stack);
// display_list(b);
// free_stack(&stack);
// free_stack(&b);
// stack = malloc(sizeof(t_stack) * )
	return EXIT_SUCCESS;
}
