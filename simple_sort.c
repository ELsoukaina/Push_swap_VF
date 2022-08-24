/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:40:26 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 21:54:48 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_a(t_stack *stack_a, t_stack *stack_b)
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

void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->values[stack_a->size - 1]
		< stack_a->values[stack_a->size - 2]
		&& stack_a->values[stack_a->size - 1] < stack_a->values[0])
		push_rotate_to_top_b(stack_a, stack_b);
	else if (stack_a->values[stack_a->size - 2]
		< stack_a->values[stack_a->size - 1]
		&& stack_a->values[stack_a->size - 2] <= stack_a->values[0])
		(void)(sa(stack_a) && ft_putstr_fd("sa\n", 1));
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 1 && !is_sorted(stack_a, stack_b))
	{
		if (stack_a->values[stack_a->size - 1] > stack_a->values[stack_a->size
				- 2] && stack_a->values[stack_a->size - 1] > stack_a->values[0])
			(void)(ra(stack_a) & ft_putstr_fd("ra\n", 1));
		else if (stack_a->values[stack_a->size - 2]
			> stack_a->values[stack_a->size - 1]
			&& stack_a->values[stack_a->size - 2] > stack_a->values[0])
			(void)(sa(stack_a) && ra(stack_a) && ft_putstr_fd("sa\nra\n", 1));
		else if (stack_a->values[0] > stack_a->values[stack_a->size - 1]
			&& stack_a->values[0] >= stack_a->values[stack_a->size - 2])
			push_min_to_b(stack_a, stack_b);
	}
	sort_b(stack_b);
	push_all_to_a(stack_a, stack_b);
}
