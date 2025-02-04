/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:39:46 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/01 20:39:47 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Moves the maximum element from stack 'b' to stack 'a'.
 * @a: Stack A.
 * @b: Stack B.
 * @max: Maximum element in stack B.
 * @size_b: Number of elements in stack B.
 */
void	return_to_a(t_stack **a, t_stack **b, t_stack *max, int size_b)
{
	int		mid;
	int		i;
	t_stack	*current;

	mid = size_b / 2;
	i = 0;
	current = *b;
	while (current)
	{
		i++;
		if (current == max)
			break ;
		current = current->next;
	}
	if (i > mid)
	{
		while (*b != max)
			rrb(b);
	}
	else
	{
		while (*b != max)
			rb(b);
	}
	pa(a, b);
}

/**
 * Pushes elements from stack 'b' to stack 'a', starting with the max element.
 * @a: Stack A.
 * @b: Stack B.
 */
void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*max;
	int		size_b;

	while (*b)
	{
		current = *b;
		max = *b;
		size_b = size_lst(*b);
		while (current)
		{
			if (current->indice > max->indice)
				max = current;
			current = current->next;
		}
		return_to_a(a, b, max, size_b);
	}
}

/**
 * Sorts stack 'a' using chunk-based push and rotate operations.
 * @a: Stack A.
 * @b: Stack B.
 * @chunk: Size of each chunk to be processed.
 */
void	sort_stack(t_stack **a, t_stack **b, int chunk)
{
	t_stack	*current;
	int		len;

	current = *a;
	while (current)
	{
		len = size_lst(*b);
		if (current->indice < len)
		{
			pb(a, b);
			rb(b);
		}
		else if (current->indice < len + chunk)
		{
			pb(a, b);
		}
		else
		{
			ra(a);
		}
		current = *a;
	}
	push_to_a(a, b);
}
