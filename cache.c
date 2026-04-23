/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:34:02 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/23 16:34:04 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cache(t_cache *cache, t_stack **stack)
{
	find_slot(&(cache->min), stack, ft_min);
	find_slot(&(cache->max), stack, ft_max);
	cache->rotation_a = 0;
	cache->rotation_b = 0;
	cache->best_cost = INT_MAX;
}

void	update_cache(t_cache *cache, int rotation_a, int rotation_b)
{
	cache->rotation_a = rotation_a;
	cache->rotation_b = rotation_b;
	cache->best_cost = ft_abs(rotation_a - rotation_b);
}

void	init_vars_turk(t_vars_turk *vars)
{
	vars->i = 0;
	vars->value = 0;
	vars->cost_a = 0;
	vars->cost_b = 0;
}
