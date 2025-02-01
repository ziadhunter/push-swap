#include "push_swap.h"

void return_to_a(t_stack **a, t_stack **b, t_stack *max, int size_b)
{
    int mid;
    int i;

    mid = size_b / 2;
    i = 0;
    t_stack *current;
    current = *b;
    while (current)
    {
        i++;
        if (current == max)
            break;
        current = current->next;
    }

    if (i > mid)
    {
        while (*b != max)
        {
            rrb(b);
            write(1,"rrb\n", 4);
        }
    }
    else
    {
        while (*b != max)
        {
            rb(b);
            write(1,"rb\n", 3);
        }
    }
    pa(a, b);
    write(1, "pa\n", 3);
}


void push_to_a(t_stack **a, t_stack **b)
{
    t_stack *current;
    t_stack *max;
    int size_b;

    while (*b)
    {
        current = *b;
        max = *b;
        size_b = size_lst(*b);

        while (current)
        {
            if (current->indice > max->indice)
                max = current;
            current = current->next;
        }
        return_to_a(a, b, max, size_b);
    }
}

void sort_stack(t_stack **a, t_stack **b, int chunk)
{
    t_stack *current;
    int len;

    current = *a;
    while (current)
    {
        len = size_lst(*b);
        if (current->indice < len)
        {
            pb(a, b);
            rb(b);
            write(1,"pb\nrb\n", 6);
        }
        else if (current->indice < len + chunk)
        {
            pb(a, b);
            write(1,"pb\n", 3);
        }
        else
        {
            ra(a);
            write(1,"ra\n", 3);
        }
        current = *a;
    }
    push_to_a(a, b);
}