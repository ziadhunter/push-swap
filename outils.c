#include "push_swap.h"

int size_lst(t_stack *a)
{
    int i;

    i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return (i);
}