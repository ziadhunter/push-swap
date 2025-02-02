/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:37:41 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/01 20:37:44 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, t_stack *min)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *a;
	while (current)
	{
		i++;
		if (current->content == min->content)
			break ;
		current = current->next;
	}
	if (i <= 2)
	{
		while ((*a)->content != min->content)
			ra(a);
	}
	else
	{
		while ((*a)->content != min->content)
			rra(a);
	}
	pb(a, b);
}

void	only_three(t_stack **a)
{
	if ((*a)->next->next != NULL)
	{
		if ((*a)->content > (*a)->next->content
			&& (*a)->content > (*a)->next->next->content)
			ra(a);
		else if ((*a)->next->content > (*a)->content
			&& (*a)->next->content > (*a)->next->next->content)
			rra(a);
	}
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	only_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a);
	push_to_b(a, b, min);
	only_three(a);
	pa(a, b);
}

void	only_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a);
	push_to_b(a, b, min);
	only_four(a, b);
	pa(a, b);
}

/**
 * hard_code - sorting a stack smaller than 5 element
*/
void	hard_code(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
		only_three(a);
	else if (size <= 4)
		only_four(a, b);
	else
		only_five(a, b);
}
