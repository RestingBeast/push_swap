/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:08:44 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/23 21:08:45 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_binary_search(int value, int *arr, int size)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == value)
			return (mid);
		if (arr[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

void	push_and_rotate(t_stack **stack_a, t_stack **stack_b, int *index)
{
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->size > 1)
		rotate_one(stack_b, 'b');
	(*index)++;
}

int	get_offset(int size)
{
	if (size <= 100)
		return (20);
	else
		return (40);
}

void	normalize_stack(t_list *lst, int size, int *arr)
{
	while (lst)
	{
		*(int *)(lst->content) = ft_binary_search(
				*(int *)(lst->content), arr, size);
		lst = lst->next;
	}
}
