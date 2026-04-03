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

# include "push_swap.h"

static int	is_valid_characters(const char *str)
{
	while (*str != '\0')
	{
		if (*str != '+' && *str != '-' && !ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	is_in_limit(const char *str)
{
	int	has_sign;
	int	len;

	has_sign = 0;
	if (*str == '+' || *str == '-')
		has_sign = 1;
	len = ft_strlen(str);
	if (len - has_sign > 10)
		return (0);
	else if (len - has_sign == 10)
	{
		return (0);
	}
	return (1);
}

int	check_inputs(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_characters(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
