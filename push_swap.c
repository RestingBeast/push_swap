/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:47:03 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/03 15:47:05 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*head_a;

	if (argc == 1)
		return (1);
	if (!check_inputs(argc, argv))
		return (display_error());
	head_a = parse_inputs(argc, argv);
	if (!head_a)
		return (display_error());
	stack_a = init_stack(head_a, ft_lstlast(head_a), ft_lstsize(head_a));
	if (!stack_a)
		return (display_error());
	stack_b = init_stack(NULL, NULL, 0);
	if (!stack_b)
		return (display_error());



	// Deleter Later
	int i = 0;
	push(&(stack_a->head), &(stack_b->head));
	push(&(stack_a->head), &(stack_b->head));
	push(&(stack_a->head), &(stack_b->head));
	t_list *iter = stack_a->head;
	while (iter)
	{
		ft_printf("Lst A%d: %d\n", ++i, *(int *)(iter->content));
		iter = iter->next;
	}
	ft_printf("\n\n");
	int j = 0;
	t_list *iter2 = stack_b->head;
	while (iter2)
	{
		ft_printf("Lst B%d: %d\n", ++j, *(int *)(iter2->content));
		iter2 = iter2->next;
	}
	// Delete Later */
	ft_printf("\n\nStack Information\n");
	ft_printf("Stack A->Head: %d\n", *(int *)(stack_a->head->content));
	ft_printf("Stack A->Tail: %d\n", *(int *)(stack_a->tail->content));
	ft_printf("Stack A->Size: %d\n", stack_a->size);
	ft_printf("Stack B->Head: %d\n", *(int *)(stack_b->head->content));
	ft_printf("Stack B->Tail: 0\n"); //, *(int *)(stack_b->tail->content));
	ft_printf("Stack B->Size: %d\n", stack_b->size);
	
	ft_lstclear(&(stack_a->head), &free);
	free(stack_a);
	ft_lstclear(&(stack_b->head), &free);
	free(stack_b);
	return (0);
}
