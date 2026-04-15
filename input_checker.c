/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:54:54 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/15 17:54:55 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_characters(const char *str)
{
	if (*str != '+' && *str != '-' && !ft_isdigit(*str))
		return (0);
	while (*(++str) != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
	}
	return (1);
}

static int	is_lower_than_max(char *str, const char *max)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (str[i] < max[i])
			return (1);
		else if (str[i] > max[i])
			return (0);
		i++;
	}
	return (1);
}

static int	count_leading_zeroes(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0' && str[count] == '0')
		count++;
	return (count);
}

static int	is_in_limit(char *str)
{
	int	sign;
	int	lead_zeroes;
	int	len;

	sign = 0;
	if (*str == '+' || *str == '-')
		sign = 1;
	lead_zeroes = count_leading_zeroes(str + sign);
	len = ft_strlen(str);
	if (len - sign - lead_zeroes > 10)
		return (0);
	else if (len - sign - lead_zeroes == 10)
	{
		if (*str == '-')
			return (is_lower_than_max(str + sign + lead_zeroes, "2147483648"));
		return (is_lower_than_max(str + sign + lead_zeroes, "2147483647"));
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
		if (!is_in_limit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
