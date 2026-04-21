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

static int	find_index_of_max(t_stack **stack)
{
	int		max;
	int		res;
	int		i;
	t_list	*lst;

	res = 0;
	i = 0;
	lst = (*stack)->head;
	max = *(int *)(lst->content);
	while (lst)
	{
		if (*(int *)(lst->content) > max)
		{
			max = *(int *)(lst->content);
			res = i;
		}
		lst = lst->next;
		i++;
	}
	return (res);
}

void	sort_three(t_stack **stack)
{
	int		max_index;

	max_index = find_index_of_max(stack);
	if (max_index == 1)
		rrotate_one(stack, 'a');
	else if (max_index == 0)
		rotate_one(stack, 'a');
	sort_two(stack);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->size > 3)
	{
		while ((*stack_a)->size > 3)
			push(stack_a, stack_b, 'b');
		sort_three(stack_a);
		// push_b_to_a
	}
	else if ((*stack_a)->size == 3)
		sort_three(stack_a);
	else if ((*stack_a)->size == 2)
		sort_two(stack_a);
}
