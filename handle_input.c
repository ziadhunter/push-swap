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
// void    ft_strcpy(char *dst, const char *src, int dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < dstsize - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// }
// char *get_next_arg(char **av, char c)
// {
//     static int i;
//     static int j;
//     int len;
//     char *str;

//     len = 0;
//     while (av[i])
//     {
//         while (av[i][j] == c)
//             j++;
//         while (av[i][j + len] && av[i][j + len] != c)
//             len++;
//         if (len != 0)
//         {
//             str = malloc (sizeof (char) * (len + 1));
//             if (!str)
//                 return (NULL);
//             return(ft_strcpy(str, av[i]+j, len+1),j += len , str);
//         }
//         i++;
//         j = 0;
//     }
// }


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct stack 
{
    long content;
    struct stack *next;
}   t_stack;

int count_num(char *str, char c)
{
    int i;
    int word;
    int count;

    count = 0;
    word = 0;
    i = 0;
    while(str[i])
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

int	ft_atol(const char *str, int len, long *content)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
        len--;
	}
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

int get_next_arg(char **av, char c, long *content)
{
    static int i;
    static int j;
    int len;

    len = 0;
    while (av[i])
    {
        while (av[i][j] == c)
            j++;
        while (av[i][j + len] && av[i][j + len] != c)
            len++;
        if (len != 0)
        {
            if (ft_atol(av[i]+j, len, content) == -1)
                return (-1);
            j += len;
            return (0);
        }
        i++;
        j = 0;
    }
    return (0);
}
void free_exit(t_stack *a)
{
    t_stack *current;
    while (a)
    {
        current = a->next;
        free(a);
        a = current;
    }
    write(1, "error\n", 6);
    exit(1);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

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
}
t_stack	*new_node(long content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
void check_duplicate(t_stack **a, long content)
{
    t_stack *current;

    if (*a == NULL)
        return;
    current = *a;
    while (current)
    {
        // printf("%ld  ====> %ld", current->content, content);
        if (current->content == content)
            free_exit(*a);
        current = current->next;
    }
}

void split(t_stack **a, char **av, char c)
{
    int i;
    int num;
    t_stack *current;
    long content;

    current = *a;
    num = 0;
    i = 0;
    while (av[i])
    {
        num += count_num(av[i], c);
        i++;
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

int main(int ac, char **av)
{
    int i;
    i = 0;
    char ** final;
    (void)ac;
    t_stack *a;
    t_stack *current;

    a = NULL;
    split(&a, av+1, ' ');
    while(a)
    {
        printf("%ld ", a->content);
        current = a->next;
        a = current ;
    }
}
