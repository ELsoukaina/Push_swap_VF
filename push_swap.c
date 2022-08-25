/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:40:14 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/25 01:25:46 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc > 1)
	{
		stack_a = parsing(stack_a, argv, argc);
		stack_b = init_stack_b(stack_a, stack_b);
		if (stack_a->size < 15)
			simple_sort(stack_a, stack_b);
		else
			compl_sort(stack_a, stack_b);
	}
	return (0);
}
