/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_outils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:20 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/03 19:12:22 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * ft_lstlast - Returns the last node of a doubly linked list.
 * @lst: The first node of the list.
 * Return: The last node or NULL if the list is empty.
 */
t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
 * ft_lstadd_back - Adds a new node to the end of a doubly linked list.
 * @lst: A pointer to the first node of the list.
 * @new: The new node to add at the end.
 *
 * If the list is empty, the new node becomes the first node.
 * Otherwise, it is linked to the last node of the list.
 */
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = ft_lstlast(*lst);
	current->next = new;
	new->prev = current;
}

/**
 * new_node - Creates a new node for a doubly linked list.
 * @content: The value to store in the node.
 * Return: A pointer to the new node or NULL on failure.
 */
t_stack	*new_node(long content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
