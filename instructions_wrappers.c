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

void	try_to_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	a1;
	int	a2;
	int	b1;
	int	b2;

	a1 = *(int *)((*stack_a)->head->content);
	a2 = *(int *)((*stack_a)->head->next->content);
	b1 = *(int *)((*stack_b)->head->content);
	b2 = *(int *)((*stack_b)->head->next->content);
	if (a1 > a2 && b1 < b2)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
	else if (a1 > a2)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (b1 < b2)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
}

/*
void	try_to_rotate(void);
{
	if ((*stack_a)->content == (*stack_a)->content && (*stack_b)->content == (*stack_b)->content)
	{}
	else if((*stack_a)->content == (*stack_a)->content)
	{}
	else if ((*stack_b)->content == (*stack_b)->content)
	{}
}

void	try_to_rrotate(void);
{
	if ((*stack_a)->content == (*stack_a)->content && (*stack_b)->content == (*stack_b)->content)
	{}
	else if((*stack_a)->content == (*stack_a)->content)
	{}
	else if ((*stack_b)->content == (*stack_b)->content)
	{}
}

void	try_to_push(void);
{
	if ((*stack_a)->content == (*stack_a)->content && (*stack_b)->content == (*stack_b)->content)
	{}
	else if((*stack_a)->content == (*stack_a)->content)
	{}
	else if ((*stack_b)->content == (*stack_b)->content)
	{}
}
*/
