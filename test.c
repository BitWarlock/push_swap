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

	i = stack->size;
	tmp = stack;
	if (i == 0)
		printf("Empty stack\n");
	else
	{
		printf("Stack: \n");
		while (1)
		{
			printf("%0d:\t%d\n", i, stack->data);
			if (stack->next == tmp)
				break ;
			stack = stack->next;
			i--;
		}
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
	*a = (*a)->prev;
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

// void	push_b(t_stack **a, t_stack **b)
// {
// 	if ((*b)->size == 0)
// 	{
// 		*b = new;
// 		(*b)->next = *b;
// 		new->prev = *b;
// 		count = 1;
// 		(*b)->size = 1;
// 		new->data = data;
// 	}
// }

void	f(void){system("leaks a.out");};

int main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6};
	int	size = sizeof(arr) / sizeof(arr[0]);
	t_stack	*stack;
	t_stack	*b;

	b = malloc(sizeof(t_stack *));
	b->next = NULL;
	b->prev = NULL;
	b->size = 0;
	create_stack(arr, size, &stack);
	rotate_a(&stack);
	reverse_ra(&stack);
	swap_a(&stack);
	swap_a(&stack);
	// push_b(&stack, &b);
	display_list(stack);
	display_list(b);
	free_stack(&stack);
	// stack = malloc(sizeof(t_stack) * )
	return EXIT_SUCCESS;
}
