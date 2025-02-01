#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct stack 
{
    long content;
    struct stack *next;
    struct stack *prev;
    int indice;
}   t_stack;


int count_num(char *str, char c);
int	ft_atol(const char *str, int len, long *content);
int get_next_arg(char **av, char c, long *content);
void free_exit(t_stack *a);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*new_node(long content);
void check_duplicate(t_stack **a, long content);
void split(t_stack **a, char **av, char c);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
//void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
///void rrr(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
int size_lst(t_stack *a);
void copy_to_temp(int dest[], int src[], int start, int count);
void merge_remaining(int arr[], int temp[], int *i, int *k, int count);
void merge(int *arr, int left, int med, int right);
void merge_sort(int *arr, int left, int right);
void set_indice(t_stack *a, int size);
void sort_stack(t_stack **a, t_stack **b, int chunk);


#endif