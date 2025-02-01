#include "push_swap.h"

void sa(t_stack **a)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)
        return;

    tmp = (*a)->next;
    (*a)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *a;
    (*a)->prev = tmp;
    tmp->next = *a;
    tmp->prev = NULL;
    *a = tmp;
}

void sb(t_stack **b)
{
    t_stack *tmp;

    if (!*b || !(*b)->next)
        return;

    tmp = (*b)->next;
    (*b)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *b;
    (*b)->prev = tmp;
    tmp->next = *b;
    tmp->prev = NULL;
    *b = tmp;
}

void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
}

void ra(t_stack **a)
{
    t_stack *last;
    t_stack *top;

    if(!*a || !(*a)->next)
        return;

    top = (*a)->next;
    last = ft_lstlast(*a);
    top->prev = NULL;
    last->next = *a;
    (*a)->prev = last;
    (*a)->next = NULL;
    *a = top;
}

void rb(t_stack **b)
{
    t_stack *last;
    t_stack *top;

    if(!*b || !(*b)->next)
        return;

    top = (*b)->next;
    last = ft_lstlast(*b);
    top->prev = NULL;
    last->next = *b;
    (*b)->prev = last;
    (*b)->next = NULL;
    *b = top;
}

void rra(t_stack **a)
{
    t_stack *last;

    if(!*a || !(*a)->next)
        return;
    last = ft_lstlast(*a);
    (last->prev)->next = NULL;
    last->next = *a;
    last->prev = NULL;
    (*a)->prev = last;
    (*a) = last;
}

void rrb(t_stack **b)
{
    t_stack *last;

    if(!*b || !(*b)->next)
        return;
    last = ft_lstlast(*b);
    (last->prev)->next = NULL;
    last->next = *b;
    last->prev = NULL;
    (*b)->prev = last;
    (*b) = last;
}

// void rrr(t_stack **a, t_stack **b)
// {
//     reverse_rotate_stack(a);
//     reverse_rotate_stack(b);
// }

void pa(t_stack **a, t_stack **b)
{
    t_stack *top_b;

    top_b = *b;
    *b = (*b)->next;
    if (*b != NULL)
        (*b)->prev = NULL;

    top_b->next = *a;
    if (*a != NULL)
        (*a)->prev = top_b;
    (*a) = top_b;
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *top_a;

    if (!*a)
        return;
    top_a = *a;
    *a = (*a)->next;
    if (*a != NULL)
        (*a)->prev = NULL;

    top_a->next = *b;
    if (*b != NULL)
        (*b)->prev = top_a;
    (*b) = top_a;
}
