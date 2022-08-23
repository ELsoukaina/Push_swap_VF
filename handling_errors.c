#include "push_swap.h"

void	print_error()
{
	ft_putstr_fd("Error !", 1);
	exit(1);
}

void	handle_double_error(char **str, int size)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
		{
			if (ft_strncmp(str[i], str[y], max_size(ft_strlen(str[i]),
						ft_strlen(str[y]))) == 0)
                print_error();
			y++;
		}
		i++;
	}
}

void	handle_stack_error(stack *stack_a, stack *stack_b)
{
	ft_putstr_fd("Error !", 1);
	free(stack_a);
	free(stack_a->values);
	if (!stack_b)
	{
		free(stack_b);
		free(stack_b->values);
	}
	exit(1);
}