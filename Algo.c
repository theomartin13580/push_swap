/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:58:02 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 15:03:32 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	where_is_the_minimum(t_stack *a, int *compteur)
{
	int	i;
	int	min;
	int	index;

	i = 1;
	min = a->data[0];
	index = 0;
	while (i < a->size)
	{
		if (a->data[i] < min)
		{
			min = a->data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	bring_index_on_top(t_stack *a, int *compteur)
{
	int	indx;

	indx = where_is_the_minimum(a, compteur);
	if (indx <= a->size / 2)
	{
		while (indx > 0)
		{
			ra(a, 1, compteur);
			indx--;
		}
	}
	else
	{
		while (indx < a->size)
		{
			rra(a, 1, compteur);
			indx++;
		}
	}
}

void	sort_stacks(t_stack *a, t_stack *b, int *compteur)
{
	while (a->size > 0)
	{
		bring_index_on_top(a, compteur);
		pb(a, b, compteur);
	}
	while (b->size > 0)
	{
		pa(a, b, compteur);
	}
}

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void    print_number(int n)
{
    char    c;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        print_number(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

static void    print_stack(char *name, t_stack *s)
{
    int    i;

    write(1, name, 2);
    write(1, ": [", 3);
    i = 0;
    while (i < s->size)
    {
        print_number(s->data[i]);
        if (i < s->size - 1)
            write(1, ", ", 2);
        i++;
    }
    write(1, "]\n", 2);
}

int    main(int ac, char **av)
{
    t_stack    a;
    t_stack    b;
    int        i;
	int compteur;

	compteur = 0;

    if (ac <= 1)
        return (0);
    a.size = ac - 1;
    b.size = 0;
    a.data = malloc(sizeof(int) * a.size);
    b.data = malloc(sizeof(int) * a.size);
    if (!a.data || !b.data)
        return (0);
    i = 1;
    while (i < ac)
    {
        a.data[i - 1] = atoi(av[i]);
        i++;
    }
    write(1, "--- AVANT TRI ---\n", 18);
    print_stack("A", &a);
    print_stack("B", &b);
    sort_stacks(&a, &b, &compteur);
    write(1, "\n--- APRES TRI ---\n", 20);
    print_stack("A", &a);
    print_stack("B", &b);
	printf("%d", compteur);
    free(a.data);
    free(b.data);
    return (0);
}