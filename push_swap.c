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
	t_list	*lst;

	if (argc == 1)
		return (1);
	lst = NULL;
	if (!check_inputs(argc, argv))
		return (display_error());
	lst = parse_inputs(argc, argv);
	if (!lst)
		return (display_error());


	// Deleter Later
	int i = 0;
	t_list *iter = lst;
	while (iter)
	{
		ft_printf("Lst %d: %d\n", ++i, *(int *)(iter->content));
		iter = iter->next;
	}
	// Delete Later
	ft_lstclear(&lst, &free);
	return (0);
}
