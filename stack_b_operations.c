/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:40:46 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 18:49:24 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size - 1 < 1)
		return (0);
	tmp = stack_b->values[stack_b->size - 1];
	stack_b->values[stack_b->size - 1] = stack_b->values[stack_b->size - 2];
	stack_b->values[stack_b->size - 2] = tmp;
	return (1);
}

int	rb(t_stack *stack_b)
{
	return (shift_top(stack_b));
}

int	rrb(t_stack *stack_b)
{
	return (shift_bottom(stack_b));
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size - 1 < 0)
		return (0);
	stack_b->size++;
	stack_b->values[stack_b->size - 1] = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = 0;
	stack_a->size--;
	return (1);
}
