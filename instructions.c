/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:54:31 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/15 17:54:33 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_list	*tmp;

	if (!stack || !((*stack)->head) || !((*stack)->head->next))
		return ;
	tmp = (*stack)->head->next;
	(*stack)->head->next = tmp->next;
	tmp->next = (*stack)->head;
	(*stack)->head = tmp;
}

void	push(t_stack **from, t_stack **to)
{
	t_list	*tmp;

	if (!from || !((*from)->head))
		return ;
	tmp = (*from)->head->next;
	if ((*to)->head == NULL)
		(*to)->tail = (*from)->head;
	ft_lstadd_front(&((*to)->head), (*from)->head);
	(*to)->size += 1;
	(*from)->size -= 1;
	(*from)->head = tmp;
}

void	rotate(t_stack **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || !((*stack)->head) || !((*stack)->head->next))
		return ;
	head = (*stack)->head->next;
	tail = (*stack)->tail;
	tail->next = (*stack)->head;
	(*stack)->head->next = NULL;
	(*stack)->tail = (*stack)->head;
	(*stack)->head = head;
}

void	rrotate(t_stack **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*new_tail;

	if (!stack || !((*stack)->head) || !((*stack)->head->next))
		return ;
	head = (*stack)->head;
	tail = (*stack)->tail;
	new_tail = head;
	while (new_tail->next != tail)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	tail->next = head;
	(*stack)->head = tail;
	(*stack)->tail = new_tail;
}
