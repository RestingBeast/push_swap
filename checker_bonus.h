/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:04:01 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/24 12:04:02 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "ftprintf/ft_printf.h"
# include "get_next_line/get_next_line.h"

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
// stack.c
t_stack	*init_stack(t_list *head, t_list *tail, int size);
int		is_sorted(t_stack *stack);
// utils.c
int		display_error(void);
// reader_bonus.c
int		ft_strequal(char *s1, const char *s2);
void	read_from_stdin(t_stack **a, t_stack **b);
// instr_checker_bonus.c
int		apply_instruction(char *instr, t_stack **a, t_stack **b);
// instructions.c
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to, char to_stack);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

#endif
