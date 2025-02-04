/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:25:17 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/02 17:25:20 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * rrr - Performs swap on both stacks.
 * @a: A pointer to the first stack.
 * @b: A pointer to the second stack.
 *
 * Calls sa on stack a and sb on stack b.
 */
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

/**
 * rrr - Performs rotations on both stacks.
 * @a: A pointer to the first stack.
 * @b: A pointer to the second stack.
 *
 * Calls ra on stack a and rb on stack b.
 */
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

/**
 * rrr - Performs reverse rotations on both stacks.
 * @a: A pointer to the first stack.
 * @b: A pointer to the second stack.
 *
 * Calls rra on stack a and rrb on stack b.
 */
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
