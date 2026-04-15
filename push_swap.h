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

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	int		size;
}	t_stack;

// input_checker.c
int		check_inputs(int argc, char **argv);
// input_parser.c
t_list	*parse_inputs(int argc, char **argv);
// instructions.c
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);
// instructions_wrappers.c
// void	try_to_swap(t_list **stack_a, t_list **stack_b);
// utils.c
int		display_error(void);
t_stack	*init_stack(t_list *head, t_list *tail, int size);
#endif
