/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:38:08 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/01 20:38:09 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * sa - Swaps the first two elements of stack 'a'.
 * @a: Pointer to the stack.
 */
void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *a;
	(*a)->prev = tmp;
	tmp->next = *a;
	tmp->prev = NULL;
	*a = tmp;
}

/**
 * ra - Rotates stack 'a' upward (first element moves to the end).
 * @a: Pointer to the stack.
 */
void	ra(t_stack **a)
{
	t_stack	*last;
	t_stack	*top;

	if (!a || !*a || !(*a)->next)
		return ;
	top = (*a)->next;
	last = ft_lstlast(*a);
	top->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	(*a)->next = NULL;
	*a = top;
}

/**
 * rra - Rotates stack 'a' downward (last element moves to the front).
 * @a: Pointer to the stack.
 */
void	rra(t_stack **a)
{
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	(last->prev)->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	(*a) = last;
}

/**
 * pa - Pushes the top element of stack 'b' to stack 'a'.
 * @a: Pointer to stack 'a'.
 * @b: Pointer to stack 'b'.
 */
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	if (!b || !*b)
		return ;
	top_b = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	top_b->next = *a;
	if (*a != NULL)
		(*a)->prev = top_b;
	(*a) = top_b;
}
