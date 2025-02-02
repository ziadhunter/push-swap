/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indice_of_each_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:39:20 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/01 20:39:24 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_remaining(int arr[], int temp[], int *k, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		arr[*k] = temp[i];
		i++;
		(*k)++;
	}
}

void	merge(int *arr, int left, int med, int right)
{
	int	*row1;
	int	*row2;

	int (i), (j), (k), (size1), (size2);
	size1 = med - left + 1;
	size2 = right - med;
	i = 0;
	j = 0;
	k = left;
	row1 = malloc(sizeof(int) * size1);
	row2 = malloc(sizeof(int) * size2);
	copy_to_temp(row1, arr, left, size1);
	copy_to_temp(row2, arr, med + 1, size2);
	while (i < size1 && j < size2)
	{
		if (row1[i] <= row2[j])
			arr[k] = row1[i++];
		else
			arr[k] = row2[j++];
		k++;
	}
	merge_remaining(arr, row1 + i, &k, size1 - i);
	merge_remaining(arr, row2 + j, &k, size2 - j);
	free(row1);
	free(row2);
}

void	merge_sort(int *arr, int left, int right)
{
	int	med;

	if (left < right)
	{
		med = left + (right - left) / 2;
		merge_sort(arr, left, med);
		merge_sort(arr, med + 1, right);
		merge(arr, left, med, right);
	}
}

void	put_indice(t_stack *a, int *arr, int size)
{
	int		i;
	t_stack	*current;

	current = a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == current->content)
			{
				current->indice = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	set_indice(t_stack *a, int size)
{
	int		*arr;
	int		i;
	t_stack	*current;

	i = 0;
	current = a;
	arr = malloc(sizeof(int) * size);
	while (current)
	{
		arr[i++] = current->content;
		current = current->next;
	}
	merge_sort(arr, 0, size - 1);
	put_indice(a, arr, size);
	free(arr);
}
