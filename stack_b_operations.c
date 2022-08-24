#include "push_swap.h"

int	sb(stack *stack_b)
{
	int	tmp;

	if (stack_b->size - 1 < 1)
		return (0);
	tmp = stack_b->values[stack_b->size - 1];
	stack_b->values[stack_b->size - 1] = stack_b->values[stack_b->size - 2];
	stack_b->values[stack_b->size - 2] = tmp;
	return (1);
}

int	rb(stack *stack_b)
{
	return (shift_top(stack_b));
}

int	rrb(stack *stack_b)
{
	return (shift_bottom(stack_b));
}

int	pb(stack *stack_a, stack *stack_b)
{
	if (stack_a->size - 1 < 0)
		return (0);
	stack_b->size++;
	stack_b->values[stack_b->size-1] = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size-1] = 0;
	stack_a->size--;
	return (1);
}