/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:09:11 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/04/23 19:09:13 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_to_array(t_list *lst, int size)
{
	int	*arr;
	int	i;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (lst)
	{
		arr[i++] = *(int *)(lst->content);
		lst = lst->next;
	}
	return (arr);
}

static void	swap_arr_element(int *arr, int *i, int *j)
{
	int	tmp;

	tmp = arr[*i];
	arr[*i] = arr[*j];
	arr[*j] = tmp;
	(*i)++;
	(*j)--;
}

static void	ft_quick_sort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	if (low >= high)
		return ;
	pivot = arr[low + (high - low) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			swap_arr_element(arr, &i, &j);
	}
	ft_quick_sort(arr, low, j);
	ft_quick_sort(arr, i, high);
}

static int	prepare_for_chunking(t_stack **stack)
{
	int	*arr;

	arr = ft_to_array((*stack)->head, (*stack)->size);
	if (!arr)
		return (0);
	ft_quick_sort(arr, 0, ((*stack)->size) - 1);
	normalize_stack((*stack)->head, (*stack)->size, arr);
	free(arr);
	return (1);
}

int	ft_wide_chunking(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	offset;

	if (!(prepare_for_chunking(stack_a)))
		return (0);
	i = 0;
	offset = get_offset((*stack_a)->size);
	while ((*stack_a)->size > 3)
	{
		if (*(int *)((*stack_a)->head->content) <= i)
			push_and_rotate(stack_a, stack_b, &i);
		else if (*(int *)((*stack_a)->head->content) <= i + offset)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate_one(stack_a, 'a');
	}
	return (1);
}
