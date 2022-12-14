/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_groups.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:39:45 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 18:35:35 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_groupes(int **groupes, int amount, int min, int max)
{
	int	i;

	i = 1;
	if (amount >= 1)
	{
		groupes[i][0] = min;
		groupes[i][1] = groupes[i][0] + (max - min) / amount;
		i++;
	}
	if (amount >= 2)
	{
		groupes[i][0] = 1 + groupes[i - 1][1];
		groupes[i][1] = groupes[i][0] + (max - min) / amount;
		i++;
	}
	if (amount >= 3)
	{
		groupes[i][0] = 1 + groupes[i - 1][1];
		groupes[i][1] = max;
	}
}

int	**get_created_groupes(t_stack *stack_a, t_stack *stack_b, int amount)
{
	int	i;
	int	min;
	int	max;
	int	**groupes;

	i = 0;
	min = get_min(stack_a);
	max = get_max(stack_a);
	groupes = (int **)malloc(sizeof(int *) * (amount + 1));
	if (!groupes)
		handle_stack_error(stack_a, stack_b);
	groupes[0] = (int *)malloc(sizeof(int));
	if (!groupes[0])
		handle_stack_error(stack_a, stack_b);
	groupes[i][0] = amount;
	while (++i <= amount)
	{
		groupes[i] = (int *)malloc(sizeof(int) * 2);
		if (!groupes)
			handle_stack_error(stack_a, stack_b);
	}
	fill_groupes(groupes, amount, min, max);
	return (groupes);
}

void	push_groupes(t_stack *stack_a, t_stack *stack_b, int *groupe)
{
	int	value;
	int	index;

	while (stack_a->size > 2 && is_ingroup(stack_a, groupe))
	{
		index = get_member_to_push(stack_a, groupe);
		value = stack_a->values[index];
		while (index > (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != value)
			(void)(ra(stack_a) && ft_putstr_fd("ra\n", 1));
		while (index <= (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != value)
			(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
		(void)(pb(stack_a, stack_b) && ft_putstr_fd("pb\n", 1));
	}
}

int	is_ingroup(t_stack	*stack, int	*group)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		if (stack->values[i] >= group[0] && stack->values[i] <= group[1])
		{
			return (1);
		}
		i--;
	}
	return (0);
}

void	move_index(t_stack *stack_b, int index, int value)
{
	while ((stack_b->size - 1) / 2 < index && value != stack_b->values[0])
	{
		(void)(rb(stack_b) && ft_putstr_fd("rb\n", 1));
	}
	while ((stack_b->size - 1) / 2 >= index && value != stack_b->values[0])
	{
		(void)(rrb(stack_b) && ft_putstr_fd("rrb\n", 1));
	}
}
