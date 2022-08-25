/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:39:06 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/25 01:00:56 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	handle_double_error(t_stack	*stack_a)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < stack_a->size)
	{
		y = i + 1;
		while (y < stack_a->size)
		{
			if (stack_a->values[i] == stack_a->values[y])
				print_error();
			y++;
		}
		i++;
	}
}

void	handle_stack_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("Error\n", 1);
	free(stack_a->values);
	free(stack_a);
	if (!stack_b)
	{
		free(stack_b->values);
		free(stack_b);
	}
	exit(1);
}

void	delete(t_stack *stack_b, int **groups, int i)
{
	free(stack_b->values);
	free(stack_b);
	free(groups[i]);
	free(groups);
}
