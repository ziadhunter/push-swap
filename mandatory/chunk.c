/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:37:18 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/07 15:56:45 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * size_of_chunk - Determines the chunk size based on the total stack size.
 * @size: The total number of elements in the stack.
 * 
 * Return: 13 if size <= 100, otherwise 33.
 */
int	size_of_chunk(int size)
{
	if (size <= 50)
		return (13);
	if (size <= 100)
		return (size / 6);
	else
		return (size / 12);
}
