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

/*static void	debug_print_stack(t_list *head)
{
	int	i = 0;
	t_list *iter = head;
	while(iter)
	{
		ft_printf("Lst %d: %d\n", ++i, *(int *)(iter->content));
		iter = iter->next;
	}
}
*/

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
	sort_stack(&stack_a, &stack_b);
	//ft_printf("\nStack A\n");
	//debug_print_stack(stack_a->head);
	ft_lstclear(&(stack_a->head), &free);
	free(stack_a);
	ft_lstclear(&(stack_b->head), &free);
	free(stack_b);
	return (0);
}
