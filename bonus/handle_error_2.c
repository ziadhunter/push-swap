/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:15:45 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/03 19:15:47 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * free_stack - Frees all nodes in a doubly linked list.
 * @a: The first node of the list.
 *
 * Iterates through the list and frees each node.
 */
void	free_stack(t_stack *a)
{
	t_stack	*current;

	while (a)
	{
		current = a->next;
		free(a);
		a = current;
	}
}

/**
 * ft_atol - Converts a string to a long integer with length validation.
 * @str: The string to convert.
 * @len: The expected length of the numeric string.
 * @content: A pointer to store the converted value.
 * Return: 0 on success, -1 on error (invalid input or overflow).
 */
int	ft_atol(const char *str, int len, long *content)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
		len--;
	}
	if (str[i] == ' ')
		return (-1);
	*content = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*content = (*content * 10) + (str[i++] - 48);
		if (*content > INT_MAX || *content < INT_MIN)
			return (-1);
		len--;
	}
	if (len != 0)
		return (-1);
	*content *= sign;
	return (0);
}

/**
 * is_sorted - Checks if a doubly linked list is sorted in ascending order.
 * @a: The first node of the list.
 * Return: 1 if sorted, 0 otherwise.
 */
int	is_sorted(t_stack *a)
{
	t_stack	*next;

	if (!a)
		return (-1);
	while (a && a->next)
	{
		next = a->next;
		if (a->content > next->content)
			return (0);
		a = next;
	}
	return (1);
}

/**
 * count_num - Counts the number of words in a string,
 *				delimited by a specific character.
 * @str: The string to search.
 * @c: The delimiter character.
 * Return: The number of words in the string.
 */
int	count_num(char *str, char c)
{
	int	i;
	int	word;
	int	count;

	count = 0;
	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && word == 0)
		{
			count++;
			word = 1;
		}
		else if (str[i] == c && word == 1)
			word = 0;
		i++;
	}
	return (count);
}
