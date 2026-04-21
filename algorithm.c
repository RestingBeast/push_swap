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
	t_list	*lst;

	max_index = find_index_of_max(stack);
	if (max_index == 1)
		rrotate(stack); // should use wrapper
	else if (max_index == 0)
		rotate(stack); // should use wrapper
	lst = (*stack)->head;
	if (*(int *)(lst->content) > *(int *)(lst->next->content))
		swap(stack);
}

void	try_to_sort();
