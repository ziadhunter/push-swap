/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:38:16 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/01 20:38:18 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * sb - Swaps the first two elements of stack 'b'.
 * @b: Pointer to the stack.
 */
void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *b;
	(*b)->prev = tmp;
	tmp->next = *b;
	tmp->prev = NULL;
	*b = tmp;
}

/**
 * rb - Rotates stack 'b' upward (first element moves to the end).
 * @b: Pointer to the stack.
 */
void	rb(t_stack **b)
{
	t_stack	*last;
	t_stack	*top;

	if (!b || !*b || !(*b)->next)
		return ;
	top = (*b)->next;
	last = ft_lstlast(*b);
	top->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	(*b)->next = NULL;
	*b = top;
}

/**
 * rrb - Rotates stack 'b' downward (last element moves to the front).
 * @b: Pointer to the stack.
 */
void	rrb(t_stack **b)
{
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	(last->prev)->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	(*b) = last;
}

/**
 * pb - Pushes the top element of stack 'a' to stack 'b'.
 * @a: Pointer to stack 'a'.
 * @b: Pointer to stack 'b'.
 */
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	if (!a || !*a)
		return ;
	top_a = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	top_a->next = *b;
	if (*b != NULL)
		(*b)->prev = top_a;
	(*b) = top_a;
}
