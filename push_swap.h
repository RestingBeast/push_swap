/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:47:09 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/03 15:47:11 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <limits.h>
# include "ftprintf/ft_printf.h"

// input_checker.c
int	check_inputs(int argc, char **argv);
// input_parser.c
t_list	*parse_inputs(int argc, char **argv);
// utils.c
int	display_error();
#endif
