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

static int	calculate_cost_b(int index, int size)
{
	int	cost_b;
	int	direction;

	cost_b = 1;
	if (index > size / 2)
	{
		cost_b += size - index;
		direction = -1;
	}
	else
	{
		cost_b += index;
		direction = 1;
	}
	return (cost_b * direction);
}

static int	calculate_cost_a(int value, t_stack **stack_a)
{
	int		cost_a;
	
	cost_a = 1;
	
	return (cost_a);
}

static int	calculate_total_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		total_cost;
	int		best_cost;
	int		i;
	t_list	*lst;

	best_cost = INT_MAX;
	i = 0;
	lst = (*stack_b)->head;
	while (lst)
	{
		cost_b = calculate_cost_b(i++, (*stack_b)->size);
		if (cost_b > best_cost)
			return (0);
		lst = lst->next;
	}
	return (best_cost);
}
