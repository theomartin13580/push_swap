/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:41:55 by theomart          #+#    #+#             */
/*   Updated: 2025/12/10 14:06:42 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack *a, int min_index)
{
	int	rotations;

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

int	find_min_index(t_stack *a)
{
	int	i;
	int	min_index;

	i = 1;
	min_index = 0;
	while (i < a->size)
	{
		if (a->data[i] < a->data[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->size > 0)
	{
		min_index = find_min_index(a);
		move_min_to_top(a, min_index);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
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

	a.size = 501; // valeurs de 500 à 0 → 501 éléments
	b.size = 0;
	a.data = malloc(sizeof(int) * a.size);
	b.data = malloc(sizeof(int) * a.size);
	if (!a.data || !b.data)
		return (0);
	i = 0;
	while (i < a.size)
	{
		a.data[i] = 500 - i; // 500, 499, 498, ..., 1, 0
		i++;
	}
	write(1, "--- AVANT TRI ---\n", 18);
	print_stack("A", &a);
	print_stack("B", &b);
	insertion_sort(&a, &b);
	write(1, "\n--- APRES TRI ---\n", 20);
	print_stack("A", &a);
	print_stack("B", &b);
	free(a.data);
	free(b.data);
	return (0);
}
