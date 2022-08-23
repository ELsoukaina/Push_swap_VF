#include "push_swap.h"

int	calc_first(int index, int size, int isa)
{
	if (index > ((size - 1) / 2))
		return (size - index);
	return (index + isa);
}

int	get_member_to_push(stack *stack, int *group)
{	
	int	index;
	int	first;
	int	second;
	int	i;

	i = stack->size - 1;
	while (i >= 0 && (stack->values[i] < group[0]
			|| stack->values[i] > group[1]))
		i--;
	index = i;
	first = calc_first(index, stack->size, 2);
	while (--i >= 0)
	{
		if (stack->values[i] >= group[0] && stack->values[i] <= group[1])
		{
			second = calc_first(i, stack->size, 2);
			if (first > second || (first == second
					&& stack->values[index] > stack->values[i]))
			{
				index = i;
				first = second;
			}
		}
	}
	return (index);
}

int	get_first(stack *b, stack *a, int limits[2], int member)
{
	int	first;
	int	first_a;
	int	place;

	first = calc_first(member, b->size, 2);
	place = a->size - 1;
	while (b->values[member] > limits[0] && b->values[member] < limits[1]
		&& place > 0 && (b->values[member] < a->values[place]
			|| b->values[member] > a->values[place - 1]))
		place--;
	while ((b->values[member] < limits[0] || b->values[member] > limits[1])
		&& place >= 0 && a->values[place] != limits[1])
		place--;
	first_a = calc_first(place, a->size, 0);
	if ((member > (b->size - 1) / 2 && place > (a->size - 1) / 2)
		|| (member <= (b->size - 1) / 2 && place <= (a->size - 1) / 2))
		first = max_size(first, first_a);
	else
		first += first_a;
	return (first);
}

int	get_member_to_push_and_sort(stack	*stack_a, stack *stack_b, int *group)
{
	int	index;
	int	first[2];
	int	limits[2];
	int	i;

	limits[0] = get_min(stack_a);
	limits[1] = get_max(stack_a);
	i = stack_b->size - 1;
	while (i >= 0 && (stack_b->values[i] < group[0]
			|| stack_b->values[i] > group[1]))
		i--;
	index = i;
	first[0] = get_first(stack_b, stack_a, limits, index);
	while (--i >= 0)
	{
		first[1] = get_first(stack_b, stack_a, limits, i);
		if (stack_b->values[i] >= group[0] && stack_b->values[i] <= group[1]
			&& (first[0] > first[1] || (first[0] == first[1]
					&& stack_b->values[index] < stack_b->values[i])))
		{
			index = i;
			first[0] = first[1];
		}
	}
	return (index);
}

void	push_to_a(stack *stack_a, stack *stack_b)
{
	int	min;

	sort_b(stack_b);
	while (stack_a->size > 1 && stack_a->values[stack_a->size - 1]
		< stack_b->values[stack_b->size - 1])
		(void)(ra(stack_a) && ft_putstr_fd("ra\n", 1));
	while (stack_b->size > 0 && stack_b->values[stack_b->size - 1]
		> stack_a->values[0])
		(void)(pa(stack_a, stack_b) && ft_putstr_fd("pa\n", 1));
	min = get_min(stack_a);
	while (min != stack_a->values[stack_a->size - 1])
		(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
}