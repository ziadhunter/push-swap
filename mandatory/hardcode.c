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

/**
 * push_to_b - Moves the smallest number in stack 'a' to stack 'b'.
 * @a: Pointer to stack 'a'.
 * @b: Pointer to stack 'b'.
 * @min: The smallest node in stack 'a'.
 * 
 * Rotates 'a' until the smallest number is at the top, 
 * then pushes it to stack 'b'.
 */
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

/**
 * only_three - Sorts a stack of three numbers.
 * @a: Pointer to stack 'a'.
 * 
 * Uses simple swaps and rotations to put the three numbers in order.
 */

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

/**
 * only_four - Sorts a stack of four numbers.
 * @a: Pointer to stack 'a'.
 * @b: Pointer to stack 'b'.
 * 
 * Moves the smallest number to 'b', sorts the remaining three numbers, 
 * then moves it back to 'a'.
 */
void	only_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a);
	push_to_b(a, b, min);
	only_three(a);
	pa(a, b);
}

/**
 * only_five - Sorts a stack of five numbers.
 * @a: Pointer to stack 'a'.
 * @b: Pointer to stack 'b'.
 * 
 * Moves the smallest number to 'b', sorts the remaining four numbers, 
 * then moves it back to 'a'.
 */

void	only_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a);
	push_to_b(a, b, min);
	only_four(a, b);
	pa(a, b);
}

/**
 * hard_code - Sorts small stacks (3 to 5 numbers).
 * @a: Pointer to stack 'a'.
 * @b: Pointer to stack 'b'.
 * @size: Number of elements in stack 'a'.
 * 
 * Calls the correct function to sort based on the stack size.
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
