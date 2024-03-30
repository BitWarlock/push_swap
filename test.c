#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_stack
{
	int	data;
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
		}
		else {
			tmp = (*stack)->prev;
			tmp->next = new;
			new->prev = tmp;
			new->next = *stack;
			tmp = *stack;
			tmp->prev = new;
		}
		// printf("in stack: %d, %d\n", i + 1, new->data);
		i++;
	}
}

void	display_list(t_stack *stack)
{
	t_stack *tmp;
	int	i;

	i = 1;
	tmp = stack;
	if (!tmp)
		exit(0);
	else
	{
		printf("Stack: \n");
		while (stack->next != tmp)
		{
			printf("%d: %d.\n", i, stack->data);
			stack = stack->next;
			i++;
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

int main(void)
{
	int	arr[15] = {-123, 52434, 5454, 5345, -765,
				756, 75, -7657657, 524656, 5346546, 543543, 5346, 0, 534};
	int	size = sizeof(arr) / sizeof(arr[0]);
	t_stack	*stack;

	create_stack(arr, size, &stack);
	display_list(stack);
	free_stack(&stack);
	// stack = malloc(sizeof(t_stack) * )
	return EXIT_SUCCESS;
}
