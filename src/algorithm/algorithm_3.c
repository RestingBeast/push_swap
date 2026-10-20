/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:42:24 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/23 18:42:25 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_simultaneous_rotations(t_stack **stack_a,
				t_stack **stack_b, t_cache *cache)
{
	if (cache->rotation_a > 0 && cache->rotation_b > 0)
	{
		rotate_both(stack_a, stack_b);
		update_rotation(&(cache->rotation_a));
		update_rotation(&(cache->rotation_b));
	}
	else if (cache->rotation_a < 0 && cache->rotation_b < 0)
	{
		rrotate_both(stack_a, stack_b);
		update_rotation(&(cache->rotation_a));
		update_rotation(&(cache->rotation_b));
	}
}

static void	do_individual_rotations(t_stack **stack, int *rotation, char name)
{
	if (*rotation > 0)
	{
		rotate_one(stack, name);
		update_rotation(rotation);
	}
	else if (*rotation < 0)
	{
		rrotate_one(stack, name);
		update_rotation(rotation);
	}
}

void	push_to_slot(t_stack **stack_a, t_stack **stack_b, t_cache *cache)
{
	while (cache->rotation_a != 0 || cache->rotation_b != 0)
	{
		if ((cache->rotation_a > 0 && cache->rotation_b > 0)
			|| (cache->rotation_a < 0 && cache->rotation_b < 0))
			do_simultaneous_rotations(stack_a, stack_b, cache);
		else if (cache->rotation_a != 0)
			do_individual_rotations(stack_a, &(cache->rotation_a), 'a');
		else if (cache->rotation_b != 0)
			do_individual_rotations(stack_b, &(cache->rotation_b), 'b');
	}
	push(stack_b, stack_a, 'a');
}
