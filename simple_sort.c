#include "push_swap.h"

void	push_all_to_A(stack *stack_a, stack *stack_b)
{
	int	i;

	i = stack_b->size;
	if (i == 0)
		return ;
	while (--i >= 0)
	{
		(void)(pa(stack_a, stack_b) && ft_putstr_fd("pa\n", 1));
	}
}

void	simple_sort(stack *stack_a, stack *stack_b)
{
	while (stack_a->size > 1 && !is_sorted(stack_a, stack_b))
	{
		if (stack_a->values[stack_a->size - 1] > stack_a->values[stack_a->size
				- 2] && stack_a->values[stack_a->size - 1] > stack_a->values[0])
			(void)(ra(stack_a) & ft_putstr_fd("ra \n", 1));
		else if (stack_a->values[stack_a->size - 2]
			> stack_a->values[stack_a->size - 1]
			&& stack_a->values[stack_a->size - 2] > stack_a->values[0])
			(void)(sa(stack_a) && ra(stack_a) && ft_putstr_fd("sa\nra\n", 1));
		else if (stack_a->values[0] > stack_a->values[stack_a->size - 1]
			&& stack_a->values[0] >= stack_a->values[stack_a->size - 2])
		{
			if (stack_a->values[stack_a->size - 1]
				< stack_a->values[stack_a->size - 2]
				&& stack_a->values[stack_a->size - 1] < stack_a->values[0])
				push_rotate_to_top_b(stack_a, stack_b);
			else if (stack_a->values[stack_a->size - 2]
				< stack_a->values[stack_a->size - 1]
				&& stack_a->values[stack_a->size - 2] <= stack_a->values[0])
				(void)(sa(stack_a) && ft_putstr_fd("sa\n", 1));
			// else if (stack_a->values[0] < stack_a->values[stack_a->size - 1]
			// 	&& stack_a->values[0] < stack_a->values[stack_a->size - 2])
			// 	(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
		}
	}
	sort_b(stack_b);
	push_all_to_A(stack_a, stack_b);
}