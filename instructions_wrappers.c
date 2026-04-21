/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_wrappers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:44:05 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/21 16:44:07 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one(t_stack **stack, char stack_name)
{
	swap(stack);
	ft_printf("s%c\n", stack_name);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	rotate_one(t_stack **stack, char stack_name)
{
	rotate(stack);
	ft_printf("r%c\n", stack_name);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
