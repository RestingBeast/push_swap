/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:25:11 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/24 12:25:27 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strequal(char *s1, const char *s2)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (len != ft_strlen(s2))
		return (0);
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	read_from_stdin(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (apply_instruction(line, a, b) == 1)
			return (free(line));
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
