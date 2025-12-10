/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:41:55 by theomart          #+#    #+#             */
/*   Updated: 2025/12/10 12:24:28 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void move_min_to_top(t_stack *a, int min_index)
{
    int rotations;

    if (min_index <= a->size / 2)
    {
        rotations = min_index;
        while (rotations--)
            ra(a, 1);
    }
    else
    {
        rotations = a->size - min_index;
        while (rotations--)
            rra(a, 1);
    }
}


int find_min_index(t_stack *a)
{
    int i = 1;
    int min_index = 0;

    while (i < a->size)
    {
        if (a->data[i] < a->data[min_index])
            min_index = i;
        i++;
    }
    return min_index;
}


void insertion_sort(t_stack *a, t_stack *b)
{
    int min_index;

    while (a->size > 0)
    {
        min_index = find_min_index(a);

        move_min_to_top(a, min_index);

        pb(a, b);      
    }
    while (b->size > 0)
        pa(a, b);     
}

#include <stdio.h>


void print_stack(const char *name, t_stack *s)
{
    printf("%s = [", name);
    for (int i = 0; i < s->size; i++)
    {
        printf("%d", s->data[i]);
        if (i < s->size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(void)
{
    int data_a[] = {
    100, 99, 98, 97, 96, 95, 94, 93, 92, 91,
    90, 89, 88, 87, 86, 85, 84, 83, 82, 81,
    80, 79, 78, 77, 76, 75, 74, 73, 72, 71,
    70, 69, 68, 67, 66, 65, 64, 63, 62, 61,
    60, 59, 58, 57, 56, 55, 54, 53, 52, 51,
    50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
    40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
    30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
    20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
    0
};


    int data_b[11] = {0};

    t_stack a = {
        .data = data_a,
        .size = 100,
        .capacity = 100
    };

    t_stack b = {
        .data = data_b,
        .size = 0,
        .capacity = 100
    };

    printf("=== Avant le tri ===\n");
    print_stack("a", &a);
    print_stack("b", &b);

    insertion_sort(&a, &b);

    printf("\n=== Après le tri ===\n");
    print_stack("a", &a);
    print_stack("b", &b);

    return 0;
}