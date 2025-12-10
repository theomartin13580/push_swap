/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:41:55 by theomart          #+#    #+#             */
/*   Updated: 2025/12/10 16:26:43 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack *a, int min_index, int *count)
{
	int	rotations;

	if (min_index <= a->size / 2)
	{
		rotations = min_index;
		while (rotations--)
			ra(a, 1, count);
	}
	else
	{
		rotations = a->size - min_index;
		while (rotations--)
			rra(a, 1, count);
	}
}

int	find_min_index(t_stack *a, int *count)
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

void	insertion_sort(t_stack *a, t_stack *b, int *count)
{
	int	min_index;

	while (a->size > 0)
	{
		min_index = find_min_index(a, count);
		move_min_to_top(a, min_index, count);
		pb(a, b, count);
	}
	while (b->size > 0)
		pa(a, b, count);
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

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		count;

	count = 0;
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
	insertion_sort(&a, &b, &count);
	write(1, "\n--- APRES TRI ---\n", 20);
	print_stack("A", &a);
	print_stack("B", &b);
	__builtin_printf("%d", count);
	free(a.data);
	free(b.data);
	return (0);
}
