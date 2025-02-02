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

#include "push_swap.h"

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *b;
	(*b)->prev = tmp;
	tmp->next = *b;
	tmp->prev = NULL;
	*b = tmp;
	write(1, "sb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*last;
	t_stack	*top;

	if (!*b || !(*b)->next)
		return ;
	top = (*b)->next;
	last = ft_lstlast(*b);
	top->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	(*b)->next = NULL;
	*b = top;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	(last->prev)->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	(*b) = last;
	write(1, "rrb\n", 4);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	if (!*a)
		return ;
	top_a = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	top_a->next = *b;
	if (*b != NULL)
		(*b)->prev = top_a;
	(*b) = top_a;
	write(1, "pb\n", 3);
}
