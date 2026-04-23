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

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	ft_min(int a, int b)
{
	return (a < b);
}

int	ft_max(int a, int b)
{
	return (a > b);
}

void	update_rotation(int *rotation)
{
	if (*rotation > 0)
		(*rotation)--;
	else if (*rotation < 0)
		(*rotation)++;
}
