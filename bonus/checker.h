/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:24:10 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/03 14:24:12 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./get_next_line/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	long			content;
	struct stack	*next;
	struct stack	*prev;
	int				indice;
}					t_stack;

/* FUNCTIONS */
void				ss(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				sb(t_stack **b);
void				rb(t_stack **b);
void				rrb(t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				pa(t_stack **a, t_stack **b);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*new_node(long content);
void				free_stack(t_stack *a);
int					ft_atol(const char *str, int len, long *content);
int					is_sorted(t_stack *a);
int					count_num(char *str, char c);
void				free_exit(t_stack *a);
int					get_next_arg(char **av, char c, long *content);
void				check_duplicate(t_stack **a, long content);
void				check_arg(char *str);
void				split(t_stack **a, char **av, char c);
int					ft_strcmp(char *s1, char *s2);
void				exit_error(char *arg, t_stack **a, t_stack **b);
void				apply_operation(t_stack **a, t_stack **b, char *arg);
void				check_input(t_stack **a, t_stack **b, int fd);
int					main(int ac, char **av);

#endif