/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:39:54 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 22:20:39 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	max_size(int s1, int s2)
{
	if (s1 > s2)
		return (s1);
	else
		return (s2);
}

t_stack	*fill_stack(t_stack *stack_a, char	**str, int size)
{
	stack_a = malloc(sizeof(t_stack));
	stack_a->values = malloc(sizeof(int) * size);
	stack_a->res_size = size;
	if (!stack_a->values)
		return (NULL);
	while (size > 0)
	{
		stack_a->values[stack_a->size] = ft_atoi(str[size - 1]);
		free(str[size - 1]);
		size--;
		stack_a->size++;
	}
	free(str);
	handle_double_error(stack_a);
	return (stack_a);
}

t_stack	*parsing(t_stack *stack_a, char	**argv, int argc)
{
	char	*tmp[2];
	char	**split;
	int		i;
	int		size;

	i = 1;
	tmp[0] = ft_strdup(argv[i]);
	while (++i < argc)
	{
		tmp[1] = ft_strjoin(tmp[0], " ");
		free(tmp[0]);
		tmp[0] = ft_strjoin(tmp[1], argv[i]);
		free(tmp[1]);
		if (argv[i][0] == '\0')
			print_error();
	}
	split = ft_split(tmp[0], ' ');
	size = args_len(split);
	stack_a = fill_stack(stack_a, split, size);
	free(tmp[0]);
	return (stack_a);
}
