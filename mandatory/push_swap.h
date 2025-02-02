/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:39:06 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/01 20:39:09 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int					main(int ac, char **av);
void				split(t_stack **a, char **av, char c);
int					count_num(char *str, char c);
void				check_arg(char *str);
int					get_next_arg(char **av, char c, long *content);
int					ft_atol(const char *str, int len, long *content);
void				free_exit(t_stack *a);
void				check_duplicate(t_stack **a, long content);
t_stack				*new_node(long content);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
int					size_lst(t_stack *a);
int					size_of_chunk(int size);
int					is_sorted(t_stack *a);
void				free_stack(t_stack *a);
void				hard_code(t_stack **a, t_stack **b, int size);
void				only_five(t_stack **a, t_stack **b);
void				only_four(t_stack **a, t_stack **b);
void				only_three(t_stack **a);
void				push_to_b(t_stack **a, t_stack **b, t_stack *min);
void				set_indice(t_stack *a, int size);
void				merge_sort(int *arr, int left, int right);
void				merge(int *arr, int left, int med, int right);
void				merge_remaining(int arr[], int temp[], int *k, int count);
void				copy_to_temp(int dest[], int src[], int start, int count);
void				sort_stack(t_stack **a, t_stack **b, int chunk);
void				push_to_a(t_stack **a, t_stack **b);
void				return_to_a(t_stack **a, t_stack **b, t_stack *max,
						int size_b);
t_stack				*find_min(t_stack *a);
void				sa(t_stack **a);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				sb(t_stack **b);
void				rb(t_stack **b);
void				rrb(t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);

#endif
