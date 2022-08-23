#include "push_swap.h"

stack	*init_stack_b(stack *stack_a, stack *stack_b)
{
	stack_b = malloc(sizeof(stack *));
	if (!stack_b)
		handle_stack_error(stack_a, stack_b);
	stack_b->values = malloc(sizeof(int *) * stack_a->res_size);
	if (!stack_b->values)
		handle_stack_error(stack_a, stack_b);
	stack_b->size = 0;
	stack_b->res_size = stack_a->res_size;
	return (stack_b);
}

int	get_max(stack *stack)
{
	int	max;
	int	i;

	i = stack->size - 1;
	max = stack->values[i];
	while (i >= 0)
	{
		if (max < stack->values[i])
			max = stack->values[i];
		i--;
	}
	return (max);
}

int	get_min(stack *stack)
{
	int	min;
	int	i;

	i = stack->size - 1;
	min = stack->values[i];
	while (i >= 0)
	{
		if (min > stack->values[i])
			min = stack->values[i];
		i--;
	}
	return (min);
}