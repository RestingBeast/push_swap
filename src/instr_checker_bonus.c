/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:27:47 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/24 14:27:49 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	do_swap(char *instr, t_stack **a, t_stack **b)
{
	if (ft_strequal(instr, "sa\n"))
		swap(a);
	else if (ft_strequal(instr, "sb\n"))
		swap(b);
	else if (ft_strequal(instr, "ss\n"))
	{
		swap(a);
		swap(b);
	}
	else
		return (display_error());
	return (0);
}

static int	do_push(char *instr, t_stack **a, t_stack **b)
{
	if (ft_strequal(instr, "pa\n"))
		push(b, a, 0);
	else if (ft_strequal(instr, "pb\n"))
		push(a, b, 0);
	else
		return (display_error());
	return (0);
}

static int	do_rotate(char *instr, t_stack **a, t_stack **b)
{
	if (ft_strequal(instr, "ra\n"))
		rotate(a);
	else if (ft_strequal(instr, "rb\n"))
		rotate(b);
	else if (ft_strequal(instr, "rr\n"))
	{
		rotate(a);
		rotate(b);
	}
	else
		return (display_error());
	return (0);
}

static int	do_rrotate(char *instr, t_stack **a, t_stack **b)
{
	if (ft_strequal(instr, "rra\n"))
		rrotate(a);
	else if (ft_strequal(instr, "rrb\n"))
		rrotate(b);
	else if (ft_strequal(instr, "rrr\n"))
	{
		rrotate(a);
		rrotate(b);
	}
	else
		return (display_error());
	return (0);
}

int	apply_instruction(char *instr, t_stack **a, t_stack **b)
{
	if (instr[0] == 's')
		return (do_swap(instr, a, b));
	else if (instr[0] == 'p')
		return (do_push(instr, a, b));
	else if (instr[0] == 'r')
	{
		if (instr[1] == 'r' && instr[2] != '\n')
			return (do_rrotate(instr, a, b));
		else
			return (do_rotate(instr, a, b));
	}
	else
		return (display_error());
}
