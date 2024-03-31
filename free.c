#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/_types/_sigaltstack.h>

typedef struct stack_t{
	int size;
	int data;
	struct stack_t *next;
	struct stack_t *prev;
}		stack;

void	add_to_stack(stack **stac, int data)
{
	static int	count;
	stack	*new;
	stack	*tmp;

	new = (stack *)malloc(sizeof(stack));
	if (count == 0)
	{
		*stac = new;
		new->next = *stac;
		new->prev = *stac;
		count = 1;
		(*stac)->size = 1;
		new->data = data;
	}
	else
	{
		tmp = (*stac)->prev;
		tmp->next = new;
		new->prev = tmp;
		new->next = *stac;
		tmp = *stac;
		tmp->prev = new;
		new->size += 1;
		(*stac)->size++;
		new->data = data;
		count++;
	}
}

void	display_list(stack *stac)
{
	stack		*tmp;
	int			i;

	i = stac->size;
	tmp = stac;
	if (i == 0)
		printf("Empty stack\n");
	else
	{
		printf("Stack: \n");
		while (1)
		{
			printf("%0d:\t%d\n", i, stac->data);
			if (stac->next == tmp)
				break ;
			stac = stac->next;
			i++;
		}
	}
}

void	free_stack(stack **stac)
{
	stack	*tmp;
	stack	*next;

	tmp = *stac;
	while ((*stac)->next != tmp)
	{
		next = (*stac)->next;
		free(*stac);
		*stac = next;
	}
	free(*stac);
}

void	f(void){system("leaks a.out");};

int main(void)
{
	atexit(f);
	int arr[4] = {1, 2, 3, 4};

	stack	*a = malloc(sizeof(stack *));

	add_to_stack(&a, 11);
	add_to_stack(&a, 22);
	add_to_stack(&a, 33);
	add_to_stack(&a, 44);
	stack *last = a->prev;
	stack *s_last = a->prev->prev;
	free(last);
	a->prev = s_last;
	s_last->next = a;
	printf("prev: %d\nnext: %d\n", a->prev->data, a->next->data);
	display_list(a);
	free_stack(&a);

	return EXIT_SUCCESS;
}
