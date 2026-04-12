# include "push_swap.h"

void	swap(t_list **stack)
{	
	t_list	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!from || !(*from))
		return;
	tmp = (*from)->next;
	ft_lstadd_front(to, (*from));
	(*from) = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || !(*stack) || !((*stack)->next))
		return;
	head = (*stack)->next;
	tail = ft_lstlast(head);
	tail->next = *stack;
	(*stack)->next = NULL;
	(*stack) = head;
}

void	rrotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*new_tail;

	if (!stack || !(*stack) || !((*stack)->next))
		return;
	head = *stack;
	tail = ft_lstlast(head);
	new_tail = head;
	while (new_tail->next != tail)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	tail->next = head;
	(*stack) = tail;
}
