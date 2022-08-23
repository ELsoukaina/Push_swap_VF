#include "push_swap.h"

int	pa(stack *stack_a, stack *stack_b)
{
	if (stack_b == NULL)
		handle_stack_error(stack_a, stack_b);
	if (stack_b->size - 1 < 0)
		return (0);
	stack_a->values[stack_a->size] = stack_b->values[stack_b->size - 1];
	stack_a->size++;
	stack_b->size--;
	return (1);
}

int	sa(stack *stack_a)
{
	int	tmp;

	if (stack_a->size - 1 < 1)
		return (0);
	tmp = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = stack_a->values[stack_a->size - 2];
	stack_a->values[stack_a->size - 2] = tmp;
	return (1);
}

int	ra(stack *stack_a)
{
	return (shift_top(stack_a));
}

int	rra(stack *stack_a)
{
	return (shift_bottom(stack_a));
}

