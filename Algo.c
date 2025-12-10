/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:58:02 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 13:56:27 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	where_is_the_minimum(t_stack *a)
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

void	bring_index_on_top(t_stack *a)
{
	int	indx;

	indx = where_is_the_minimum(a);
	if (indx <= a->size / 2)
	{
		while (indx > 0)
		{
			ra(a, 1);
			indx--;
		}
	}
	else
	{
		while (indx < a->size)
		{
			rra(a, 1);
			indx++;
		}
	}
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	while (a->size > 0)
	{
		bring_index_on_top(a);
		pb(a, b);
	}
	while (b->size > 0)
	{
		pa(a, b);
	}
}

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	print_number(int n)
{
	char	c;

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

static void	print_stack(char *name, t_stack *s)
{
	int	i;

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

int	main(void)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		compteur;

	a.data = malloc(sizeof(int) * 101);
	b.data = malloc(sizeof(int) * 101);
	if (!a.data || !b.data)
		return (0);
	a.size = 101;
	b.size = 0;
	i = 0;
	while (i < 101)
	{
		a.data[i] = 100 - i;
		i++;
	}
	write(1, "\n--- AVANT TRI ---\n", 19);
	print_stack("A", &a);
	print_stack("B", &b);
	sort_stacks(&a, &b);
	write(1, "\n--- APRES TRI ---\n", 20);
	print_stack("A", &a);
	print_stack("B", &b);
	free(a.data);
	free(b.data);
	return (0);
}
