#include "push_swap.h"

void	push_and_sort_group(stack *stack_a, stack *stack_b, int *group)
{
	int	items[2];
	int	places[2];
	int	min;
	int	max;

	while (is_ingroup(stack_b, group))
	{
		min = get_min(stack_a);
		max = get_max(stack_a);
		places[0] = get_member_to_push_and_sort(stack_a, stack_b, group);
		
		items[0] = stack_b->values[places[0]];
		places[1] = stack_a->size - 1;
		while (items[0] > min && items[0] < max && places[1] > 0
			&& (items[0] < stack_a->values[places[1]]
				|| items[0] > stack_a->values[places[1] - 1]))
			places[1]--;
		while ((items[0] < min || items[0] > max) && places[1] >= 0
			&& stack_a->values[places[1]] != max)
			places[1]--;
		items[1] = stack_a->values[places[1]];
		// rotate stack
		while (places[0] > (stack_b->size - 1) / 2 && stack_b->values[stack_b->size - 1] != items[0]
		&& places[1] > (stack_a->size - 1) / 2 && stack_a->values[0] != items[1])
			(void)(rr(stack_a, stack_b) && ft_putstr_fd("rr\n", 1));
		while (places[0] > (stack_b->size - 1) / 2 && stack_b->values[stack_b->size - 1] != items[0])
			(void)(rb(stack_b) && ft_putstr_fd("rb\n", 1));
		while (places[1] > (stack_a->size - 1) / 2 && stack_a->values[0] != items[1])
			(void)(ra(stack_a) && ft_putstr_fd("ra\n", 1));
		// reverse rotate
		while (places[0] <= (stack_b->size - 1) / 2 && stack_b->values[stack_b->size - 1] != items[0]
		&& places[1] <= (stack_a->size - 1) / 2 && stack_a->values[0] != items[1])
			(void)(rrr(stack_a, stack_b) && ft_putstr_fd("rrr\n", 1));
		while (places[0] <= (stack_b->size - 1) / 2 && stack_b->values[stack_b->size - 1] != items[0])
			(void)(rrb(stack_b) && ft_putstr_fd("rrb\n", 1));
		while (places[1] <= (stack_a->size - 1) / 2 && stack_a->values[0] != items[1])
			(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
		// reverse_rotate_stacks(stack_a, stack_b, items, places);
		(void)(pa(stack_a, stack_b) && ft_putstr_fd("pa\n", 1));
	}
}

void	compl_sort(stack *stack_a, stack *stack_b)
{
	int	**groups;
	int	amount;
	int	i;

	if (stack_a->size < 75)
		amount = 1;
	else if (stack_a->size < 100)
		amount = 2;
	else
		amount = 3;
	groups = get_created_groupes(stack_a, stack_b, amount);
	// i = 0;
	// while(++i<=groups[0][0])
	// 	printf("groups : %d\t",groups[i][1]);
	i=0;
	while (++i <= groups[0][0])
		push_groupes(stack_a, stack_b, groups[i]);
	i = groups[0][0];
	while (i > 0)
	{
		push_and_sort_group(stack_a, stack_b, groups[i]);
		free(groups[i--]);
	}
	delete(stack_b, groups, i);
	sort_a(stack_a);
}