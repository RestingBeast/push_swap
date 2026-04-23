/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:47:09 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/03 15:47:11 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "ftprintf/ft_printf.h"

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	int		size;
}	t_stack;

typedef struct s_slot
{
	int	value;
	int	pos;
}	t_slot;

typedef struct s_cache
{
	t_slot	max;
	t_slot	min;
	int		rotation_a;
	int		rotation_b;
	int		best_cost;
}	t_cache;

typedef struct s_vars_turk
{
	int	i;
	int	value;
	int	cost_a;
	int	cost_b;
}	t_vars_turk;

// algorithm.c
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	do_the_turk(t_stack **stack_a, t_stack **stack_b);
int		index_calculation(int index, int size);
void	push_to_slot(t_stack **stack_a, t_stack **stack_b, t_cache *cache);
// cache.c
void	init_cache(t_cache *cache, t_stack **stack);
void	update_cache(t_cache *cache, int rotation_a, int rotation_b);
void	init_vars_turk(t_vars_turk *vars);
// chunking.c
int		get_offset(int size);
void	normalize_stack(t_list *lst, int size, int *arr);
int		ft_butterfly_chunk(t_stack **stack_a, t_stack **stack_b);
void	push_and_rotate(t_stack **stack_a, t_stack **stack_b, int *index);
// input_checker.c
int		check_inputs(int argc, char **argv);
// input_parser.c
t_list	*parse_inputs(int argc, char **argv);
// instructions.c
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to, char to_stack);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);
// instructions_wrappers.c
void	swap_one(t_stack **stack, char stack_name);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	rotate_one(t_stack **stack, char stack_name);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	rrotate_one(t_stack **stack, char stack_name);
void	rrotate_both(t_stack **stack_a, t_stack **stack_b);
// stack.c
t_stack	*init_stack(t_list *head, t_list *tail, int size);
int		is_sorted(t_stack *stack);
void	find_slot(t_slot *slot, t_stack **stack, int (*f)(int, int));
// utils.c
int		display_error(void);
int		ft_abs(int n);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	update_rotation(int *rotation);

#endif 
