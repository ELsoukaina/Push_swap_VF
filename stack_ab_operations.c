/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:40:43 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 23:37:42 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	return (ra(stack_a) * rb(stack_b));
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	return (sa(stack_a) * sb(stack_b));
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	return (rra(stack_a) * rrb(stack_b));
}

int	shift_down(t_stack *stack)
{
	int	down;
	int	i;

	down = stack->values[0];
	i = 0;
	if (stack->size - 1 <= 0)
		return (0);
	while (i <= stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->size - 1] = down;
	return (1);
}

int	shift_up(t_stack *stack)
{
	int	up;
	int	i;

	up = stack->values[stack->size - 1];
	i = stack->size - 1;
	if (i <= 0)
		return (0);
	while (i >= 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = up;
	return (1);
}
