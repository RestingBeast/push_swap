/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:58:46 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/15 17:58:47 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	display_error(void)
{
	ft_printf("Error\n");
	return (1);
}

t_stack *init_stack(t_list *head, t_list *tail, int size)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = head;
	stack->tail = tail;
	stack->size = size;
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	t_list	*lst;

	lst = stack->head;
	while (lst->next)
	{
		if (*(int *)(lst->content) > *(int *)(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}
