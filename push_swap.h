/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:38:58 by sel-jala          #+#    #+#             */
/*   Updated: 2022/08/24 22:27:57 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}	t_stack;

void	fill_groupes(int **groupes, int size, int min, int max);
int		**get_created_groupes(t_stack *stack_a, t_stack *stack_b, int size);
void	push_groupes(t_stack *stack_a, t_stack *stack_b, int *groupe);
int		is_ingroup(t_stack *stack, int	*group);
void	delete(t_stack *stack_b, int **groups, int i);
void	move_index(t_stack *stack_b, int index, int value);
int		calc_first(int index, int size, int isa);
int		get_member_to_push(t_stack *stack, int *group);
int		get_first(t_stack *b, t_stack *a, int limits[2], int member);
int		get_member_push_sort(t_stack *stack_a, t_stack *stack_b, int *group);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	rotate_stack(t_stack *stack_a, t_stack *stack_b, int *p, int *items);
void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, int *p, int *items);
void	push_and_sort_group(t_stack *stack_a, t_stack *stack_b, int *group);
void	compl_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_b(t_stack *stack_b);
void	sort_a(t_stack *stack_a);
int		b_is_sorted(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack_a, t_stack *stack_b);
void	push_rotate_to_top_b(t_stack *stack_a, t_stack *stack_b);
void	_to_A(t_stack *stack_a, t_stack *stack_b);
void	push_min_to_b(t_stack *stack_a, t_stack *stack_b);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
t_stack	*init_stack_b(t_stack *stack_a, t_stack *stack_b);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		args_len(char **str);
int		max_size(int s1, int s2);
t_stack	*fill_stack(t_stack *stack_a, char	**str, int size);
t_stack	*parsing(t_stack *stack_a, char	**argv, int argc);
void	print_error(void);
void	handle_double_error(t_stack *stack_a);
void	handle_stack_error(t_stack *stack_a, t_stack *stack_b);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_isdigit(int d);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *source);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *str1, const void *str2, size_t n);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		sa(t_stack *stack_a);
int		ra(t_stack *stack_a);
int		rra(t_stack *stack_a);
int		pb(t_stack *stack_a, t_stack *stack_b);
int		sb(t_stack *stack_b);
int		rb(t_stack *stack_b);
int		rrb(t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);
int		shift_bottom(t_stack *stack);
int		shift_top(t_stack *stack);
#endif
