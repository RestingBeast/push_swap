/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:43:31 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/21 22:43:33 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_calculation(int index, int size)
{
	if (index > size / 2)
		return ((size - index) * (-1));
	else
		return (index);
}

static int	get_index_to_push(int val, t_list *lst)
{
	int	predecessor;
	int	res;
	int	i;

	res = 0;
	predecessor = 0;
	i = 0;
	while (lst)
	{
		if (val > *(int *)(lst->content) &&
			*(int *)(lst->content) > predecessor)
		{
			predecessor = *(int *)(lst->content);
			res = i + 1;
		}
		i++;
		lst = lst->next;
	}
	return (res);
}

static int	find_pos_a(int val, t_list *lst, t_cache *cache)
{
	if (val < cache->min.value)
		return (cache->min.pos);
	else if (val > cache->max.value)
		return (cache->max.pos + 1);
	else
		return (get_index_to_push(val, lst));
}

static void	push_to_slot(t_stack **stack_a, t_stack **stack_b, t_cache *cache)
{
	while (cache->rotation_a != 0 || cache->rotation_b != 0)
	{
		if (cache->rotation_a > 0 && cache->rotation_b > 0)
			rotate_both(stack_a, stack_b);
		else if (cache->rotation_a < 0 && cache->rotation_b < 0)
			rrotate_both(stack_a, stack_b);
		else if (cache->rotation_a > 0)
			rotate_one(stack_a, 'a');
		else if (cache->rotation_a < 0)
			rrotate_one(stack_a, 'a');
		else if (cache->rotation_b > 0)
			rotate_one(stack_b, 'b');
		else if (cache->rotation_b < 0)
			rrotate_one(stack_b, 'b');
		update_rotation(&(cache->rotation_a));
		update_rotation(&(cache->rotation_b));
	}
	push(stack_b, stack_a, 'a');
}

void	do_the_turk(t_stack **stack_a, t_stack **stack_b)
{
	t_vars_turk	vars;
	t_cache		cache;
	t_list		*lst;

	init_vars_turk(&vars);
	init_cache(&cache, stack_a);
	lst = (*stack_b)->head;
	while (lst)
	{
		vars.value = *(int *)(lst->content);
		lst = lst->next;
		vars.cost_b = index_calculation((vars.i)++, (*stack_b)->size);
		if (ft_abs(vars.cost_b) >= cache.best_cost)
			continue ;
		vars.cost_a = index_calculation(find_pos_a(vars.value,
					(*stack_a)->head, &cache), (*stack_a)->size);
		if (ft_abs(vars.cost_a - vars.cost_b) < cache.best_cost)
			update_cache(&cache, vars.cost_a, vars.cost_b);
	}
	push_to_slot(stack_a, stack_b, &cache);
}
