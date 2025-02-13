/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:47:42 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/19 17:20:12 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * free_exit - free all the stack and exit from the programe
 * @ *a the stack to free
*/
void	free_exit(t_stack *a)
{
	t_stack	*current;

	while (a)
	{
		current = a->next;
		free(a);
		a = current;
	}
	write(1, "Error\n", 6);
	exit(1);
}

/**
 * get_next_arg - get the next valid paramet from the argument
 * @ **av double pointer includes all parameters given by the user
 * @ c the split char wich is ' '
 * @ *content a pointer of int take the new paramet  
*/
int	get_next_arg(char **av, char c, long *content)
{
	static int	i;
	static int	j;
	int			len;

	len = 0;
	*content = 0;
	while (av[i])
	{
		while (av[i][j] == c)
			j++;
		while (av[i][j + len] && av[i][j + len] != c)
			len++;
		if (len != 0)
		{
			if (ft_atol(av[i] + j, len, content) == -1)
				return (-1);
			j += len;
			return (0);
		}
		i++;
		j = 0;
	}
	return (0);
}

/**
 * check_duplicate - check if the stack have a duplicate numeric parameter.
 * 					if so, The program must display "Error".
 * @ **a	: the stack
 * @ content: the new arg that would check if he is already on the stack
 */
void	check_duplicate(t_stack **a, long content)
{
	t_stack	*current;

	if (*a == NULL)
		return ;
	current = *a;
	while (current)
	{
		if (current->content == content)
			free_exit(*a);
		current = current->next;
	}
}

/**
 * check_arg - check if the arg is NULL or have only spaces
 * @*str pointer of the argument 
 */
void	check_arg(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (str[i])
	{
		if (str[i] != ' ')
			return ;
		i++;
	}
	write(1, "Error\n", 6);
	exit(1);
}

/**
 * split - split all the argument by space
 * @ **a stack that will have all the arguments given by the av
 * @ **av double pointer includes all parameters given by the user
 * @ c characterthat split the argument 
 */
void	split(t_stack **a, char **av, char c)
{
	int		i;
	int		num;
	t_stack	*current;
	long	content;

	current = *a;
	num = 0;
	i = 0;
	while (av[i])
	{
		num += count_num(av[i], c);
		check_arg(av[i++]);
	}
	i = 0;
	while (i < num)
	{
		if (get_next_arg(av, c, &content) == -1)
			free_exit(*a);
		check_duplicate(a, content);
		current = new_node(content);
		if (!current)
			free_exit(*a);
		ft_lstadd_back(a, current);
		i++;
	}
}
