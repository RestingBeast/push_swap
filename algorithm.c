/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_wrappers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:54:41 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/15 17:54:43 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	t_list	*lst;

	lst = (*stack)->head;
	if (*(int *)(lst->content) > *(int *)(lst->next->content))
		swap_one(stack, 'a');
}

void	sort_three(t_stack **stack)
{
	t_slot	max;

	find_slot(&max, stack, ft_max);
	if (max.pos == 1)
		rrotate_one(stack, 'a');
	else if (max.pos == 0)
		rotate_one(stack, 'a');
	sort_two(stack);
}

static void	rotate_to_correct_position(t_stack **stack)
{
	t_slot	min;
	int		rotation;

	find_slot(&min, stack, ft_min);
	rotation = index_calculation(min.pos, (*stack)->size);
	while (rotation != 0)
	{
		if (rotation > 0)
			rotate_one(stack, 'a');
		else if (rotation < 0)
			rrotate_one(stack, 'a');
		update_rotation(&rotation);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->size > 3)
	{
		ft_wide_chunking(stack_a, stack_b);
		sort_three(stack_a);
		while ((*stack_b)->size > 0)
			do_the_turk(stack_a, stack_b);
		rotate_to_correct_position(stack_a);
	}
	else if ((*stack_a)->size == 3)
		sort_three(stack_a);
	else if ((*stack_a)->size == 2)
		sort_two(stack_a);
}
