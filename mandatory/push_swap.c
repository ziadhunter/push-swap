/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:26:12 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/02 17:26:13 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * main - Entry point for the push_swap program.
 * @ac: Argument count.
 * @av: Argument vector (array of input strings).
 * 
 * 1. Initializes two stacks (a and b).
 * 2. Parses input arguments and fills stack 'a'.
 * 3. If the stack is already sorted, it frees memory and exits.
 * 4. If the stack has 5 or fewer elements, it uses a hard-coded sorting method.
 * 5. If the stack has more than 5 elements,
 *			it assigns indices and sorts using a chunk-based algorithm.
 * 6. Frees allocated memory before exiting.
 * 
 * Returns 0 upon successful execution.
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		split(&a, av + 1, ' ');
		if (is_sorted(a) == 1)
			free_stack(a);
		else
		{
			size = size_lst(a);
			if (size_lst(a) <= 5)
				hard_code(&a, &b, size);
			else
			{
				set_indice(a, size);
				sort_stack(&a, &b, size_of_chunk(size_lst(a)));
			}
			free_stack(a);
		}
	}
	return (0);
}
