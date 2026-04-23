/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:12:05 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/22 16:12:06 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	find_slot(t_slot *slot, t_stack **stack, int (*f)(int, int))
{
	t_list	*lst;
	int		i;

	slot->value = *(int *)((*stack)->head->content);
	slot->pos = 0;
	i = 1;
	lst = (*stack)->head->next;
	while (lst)
	{
		if (f(*(int *)(lst->content), slot->value))
		{
			slot->value = *(int *)(lst->content);
			slot->pos = i;
		}
		lst = lst->next;
		i++;
	}
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
