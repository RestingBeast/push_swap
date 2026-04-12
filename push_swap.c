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
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (1);
	if (!check_inputs(argc, argv))
		return (display_error());
	stack_a = parse_inputs(argc, argv);
	if (!stack_a)
		return (display_error());
	stack_b = NULL;

	// Deleter Later
	int i = 0;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	rrotate(&stack_a);
	t_list *iter = stack_a;
	while (iter)
	{
		ft_printf("Lst A%d: %d\n", ++i, *(int *)(iter->content));
		iter = iter->next;
	}
	ft_printf("\n\n");
	int j = 0;
	rotate(&stack_b);
	swap(&stack_b);
	t_list *iter2 = stack_b;
	while (iter2)
	{
		ft_printf("Lst B%d: %d\n", ++j, *(int *)(iter2->content));
		iter2 = iter2->next;
	}
	// Delete Later
	
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
