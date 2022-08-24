/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:40:23 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 22:28:35 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_first(int index, int size, int isa)
{
	if (index > (size - 1) / 2)
		return (size - index);
	else if (index + isa < size)
		return (index + isa);
	return (index + 1);
}

int	get_member_to_push(t_stack *stack, int *group)
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

int	get_first(t_stack *stack_a, t_stack *stack_b, int limits[2], int member)
{
	int	first;
	int	first_a;
	int	place;

	first = calc_first(member, stack_b->size, 2);
	place = stack_a->size - 1;
	while (stack_b->values[member] > limits[0]
		&& stack_b->values[member] < limits[1]
		&& place > 0 && (stack_b->values[member] < stack_a->values[place]
			|| stack_b->values[member] > stack_a->values[place - 1]))
		place--;
	while ((stack_b->values[member] < limits[0]
			|| stack_b->values[member] > limits[1])
		&& place >= 0 && stack_a->values[place] != limits[1])
		place--;
	first_a = calc_first(place, stack_a->size, 0);
	if ((member > (stack_b->size - 1) / 2 && place > (stack_a->size - 1) / 2)
		|| (member <= (stack_b->size - 1) / 2
			&& place <= (stack_a->size - 1) / 2))
		first = max_size(first, first_a);
	else
		first += first_a;
	return (first);
}

int	get_member_push_sort(t_stack	*stack_a, t_stack *stack_b, int *group)
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
	first[0] = get_first(stack_a, stack_b, limits, index);
	while (--i >= 0)
	{
		first[1] = get_first(stack_a, stack_b, limits, i);
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

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
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
