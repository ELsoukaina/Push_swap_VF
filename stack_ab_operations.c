#include "push_swap.h"

int	rr(stack *stack_a, stack *stack_b)
{
	return (ra(stack_a) * rb(stack_b));
}

int	ss(stack *stack_a, stack *stack_b)
{
	return (sa(stack_a) * sb(stack_b));
}

int	rrr(stack *stack_a, stack *stack_b)
{
	return (rra(stack_a) * rrb(stack_b));
}

int	shift_bottom(stack *stack)
{
	int	bottom;
	int	i;

	bottom = stack->values[0];
	i = 0;
	if (stack->size - 1 <= 0)
		return (0);
	while (i <= stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->size - 1] = bottom;
	return (1);
}

int	shift_top(stack *stack)
{
	int	top;
	int	i;

	top = stack->values[stack->size - 1];
	i = stack->size - 1;
	if (i <= 0)
		return (0);
	while (i >= 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = top;
	return (1);
}
