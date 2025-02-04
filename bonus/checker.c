/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:31 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/03 12:31:35 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * ft_strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: Difference between the first non-matching characters, or -1 if NULL.
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

/**
 * exit_error - Prints an error message, frees memory, and exits the program.
 * @arg: The argument to free.
 * @a: Pointer to the first stack.
 * @b: Pointer to the second stack.
 */
void	exit_error(char *arg, t_stack **a, t_stack **b)
{
	write(1, "Error\n", 6);
	free_stack(*a);
	free_stack(*b);
	free(arg);
	exit(1);
}

/**
 * apply_operation - Executes a stack operation based on the given command.
 * @a: Pointer to the first stack.
 * @b: Pointer to the second stack.
 * @arg: The operation command as a string.
 */
void	apply_operation(t_stack **a, t_stack **b, char *arg)
{
	if (ft_strcmp(arg, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(arg, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(arg, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(arg, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(arg, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(arg, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(arg, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(arg, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(arg, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(arg, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(arg, "rrr\n") == 0)
		rrr(a, b);
	else
		exit_error(arg, a, b);
}

/**
 * check_input - Reads and applies operations from the input file descriptor.
 * @a: Pointer to the first stack.
 * @b: Pointer to the second stack.
 * @fd: The file descriptor to read from.
 */
void	check_input(t_stack **a, t_stack **b, int fd)
{
	char	*arg;

	arg = get_next_line(fd);
	while (arg)
	{
		apply_operation(a, b, arg);
		free(arg);
		arg = get_next_line(fd);
	}
}

/** 
 * main - Entry point for the push swap checker program.
 * @ac: Argument count.
 * @av: Argument vector.
 * Return: 0 on successful execution.
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		split(&a, av + 1, ' ');
		check_input(&a, &b, 0);
		if (is_sorted(a) == 1 && b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stack(b);
		free_stack(a);
	}
}
