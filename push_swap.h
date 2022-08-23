#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*values;
	int	size;
	int	res_size;
}	stack;

// *********** MANAGE GROUPS ***********
void	fill_groupes(int **groupes, int size, int min, int max);
int		**get_created_groupes(stack *stack_a, stack *stack_b, int size);
void	push_groupes(stack *stack_a, stack *stack_b, int *groupe);
int		is_ingroup(stack	*stack, int	*group);
void	delete(stack *stack_b, int **groups, int i);
void	move_index(stack *stack_b, int index, int value);
// *********** PUSH (COMPLEX) ***********
int		calc_first(int index, int size, int isa);
int		get_member_to_push(stack *stack, int *group);
int		get_first(stack *b, stack *a, int limits[2], int member);
int		get_member_to_push_and_sort(stack	*stack_a, stack *stack_b, int *group);
void	push_to_a(stack *stack_a, stack *stack_b);
// *********** COMPLEX SORT ***********
void	push_and_sort_group(stack *stack_a, stack *stack_b, int *group);
void	compl_sort(stack *stack_a, stack *stack_b);
// *********** SORT ***********
void	sort_b(stack *stack_b);
void	sort_a(stack *stack_a);
int	    b_is_sorted(stack *stack_a, stack *stack_b);
int	    is_sorted(stack *stack_a, stack *stack_b);
void	push_rotate_to_top_b(stack *stack_a, stack *stack_b);
// *********** SIMPLE SORT ***********
void	push_all_to_A(stack *stack_a, stack *stack_b);
void	simple_sort(stack *stack_a, stack *stack_b);
// *********** INISIALISER ***********
stack	*init_stack_b(stack *stack_a, stack *stack_b);
int	    get_max(stack *stack);
int	    get_min(stack *stack);
// *********** PARSING ***********
int		args_len(char **str);
int		max_size(int s1, int s2);
stack	*fill_stack(stack	*stack_a, char	**str, int size);
stack	*parsing(stack	*stack_a, char	**argv, int argc);
// *********** ERRORS ***********
void	print_error();
void	handle_double_error(char **str, int size);
void	handle_stack_error(stack *stack_a, stack *stack_b);
// *********** UTILS ***********
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	    ft_strncmp(const char *str1, const char *str2, size_t n);
int	    ft_isdigit(int d);
int	    ft_atoi(const char *str);
char	*ft_strdup(const char *source);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int 	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *str1, const void *str2, size_t n);
// *********** OPERATIONS ***********
int		pa(stack *stack_a, stack *stack_b);
int		sa(stack *stack_a);
int		ra(stack *stack_a);
int		rra(stack *stack_a);
int		pb(stack *stack_a, stack *stack_b);
int		sb(stack *stack_b);
int		rb(stack *stack_b);
int		rrb(stack *stack_b);
int		rr(stack *stack_a, stack *stack_b);
int		ss(stack *stack_a, stack *stack_b);
int		rrr(stack *stack_a, stack *stack_b);
int		shift_bottom(stack *stack);
int		shift_top(stack *stack);
#endif