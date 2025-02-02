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
}
