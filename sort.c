#include "push_swap.h"

void	sort_b(stack *stack_b)
{
	int	index;
	int	max;

	if (stack_b->size - 1 > 0)
	{
		max = get_max(stack_b);
		index = stack_b->size - 1;
		while (stack_b->values[index] != max && index >= 0)
			index--;
		while (stack_b->values[stack_b->size - 1] != max && index
			> (stack_b->size - 1) / 2)
			(void)(rb(stack_b) && ft_putstr_fd("rb\n", 1));
		while (stack_b->values[stack_b->size - 1] != max && index
			<= (stack_b->size - 1) / 2)
			(void)(rrb(stack_b) && ft_putstr_fd("rrb\n", 1));
	}
}

void	sort_a(stack *stack_a)
{
	int	index;
	int	min;

	if (stack_a->size > 1)
	{
		min = get_min(stack_a);
		index = stack_a->size - 1;
		while (index >= 0 && stack_a->values[index] != min)
			index--;
		while (index > (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != min)
			(void)(ra(stack_a) && ft_putstr_fd("ra\n", 1));
		while (index <= (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != min)
			(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
	}
}

int	b_is_sorted(stack *stack_a, stack *stack_b)
{
	int	tmp;
	int	i;
	int	max;
	int	min;

	i = stack_b->size - 1;
	tmp = stack_b->values[i];
	max = get_max(stack_b);
	min = get_min(stack_b);
	if (i >= 0)
	{
		while (--i > 0)
		{
			if (tmp < stack_b->values[i] && min != tmp)
				return (0);
			tmp = stack_a->values[i];
		}
		if (stack_a->size > 0 && max > stack_a->values[stack_a->size - 1])
		{
			push_to_a(stack_a, stack_b);
		}
	}
	return (1);
}

int	is_sorted(stack *stack_a, stack *stack_b)
{
	int	tmp;
	int	i;

	i = stack_a->size - 1;
	if (i > 0)
	{
		tmp = stack_a->values[i];
		while (--i >= 0)
		{
			if (tmp > stack_a->values[i])
				return (0);
			tmp = stack_a->values[i];
		}
	}
	return (b_is_sorted(stack_a, stack_b));
}

void	push_rotate_to_top_b(stack *stack_a, stack *stack_b)
{
	int	index;
	int	min;
	int	max;

	if (stack_b->size > 1)
	{
		index = stack_b->size - 1;
		min = get_min(stack_b);
		max = get_max(stack_b);
		while (stack_a->values[stack_a->size - 1] < max
			&& stack_a->values[stack_a->size - 1] > min && index
			> 0 && (stack_b->values[index]
				< stack_a->values[stack_a->size - 1]
				|| stack_b->values[index - 1]
				> stack_a->values[stack_a->size - 1]))
			index--;
		while ((stack_a->values[stack_a->size - 1] > max
				|| stack_a->values[stack_a->size - 1] < min) && index >= 0
			&& stack_b->values[index] != min)
			index--;
		move_index(stack_b, index, stack_b->values[index]);
	}
	(void)(pb(stack_a, stack_b) && ft_putstr_fd("pb\n", 1));
}
