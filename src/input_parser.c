/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:46:50 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/03 15:46:52 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	is_a_dupe(int value, t_list *lst)
{
	while (lst)
	{
		if (value == *(int *)(lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*parse_inputs(int argc, char **argv)
{
	t_list	*res;
	t_list	*lst;
	int		*ptr;
	int		value;
	int		i;

	res = NULL;
	i = 0;
	while (++i < argc)
	{
		value = ft_atoi(argv[i]);
		if (is_a_dupe(value, res))
			return (ft_lstclear(&res, &free), NULL);
		ptr = malloc(sizeof(int *));
		if (!ptr)
			return (ft_lstclear(&res, &free), NULL);
		*ptr = value;
		lst = ft_lstnew(ptr);
		if (!lst)
			return (ft_lstclear(&res, &free), NULL);
		ft_lstadd_back(&res, lst);
	}
	return (res);
}
