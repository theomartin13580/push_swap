/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:13:50 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 14:25:52 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int c, int *compteur)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = tmp;
	if (c == 1)
	{
		write(1, "sa\n", 3);
		(*compteur) ++;
	}
}

void	sb(t_stack *b, int c, int *compteur)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = tmp;
	if (c == 1)
	{
		write(1, "sb\n", 3);
		(*compteur) ++;
	}
}

void	ss(t_stack *a, t_stack *b, int *compteur)
{
	sa(a, 0, compteur);
	sb(b, 0, compteur);
	write(1, "ss\n", 3);
	(*compteur) ++;

}

void	pa(t_stack *a, t_stack *b, int *compteur)
{
	int	i;

	if (b->size == 0)
		return ;
	// décaler a vers le haut pour faire de la place
	for (i = a->size; i > 0; i--)
		a->data[i] = a->data[i - 1];
	// on met b->data[0] dans a->data[0]
	a->data[0] = b->data[0];
	a->size++;
	// décaler b vers le bas
	for (i = 0; i < b->size - 1; i++)
		b->data[i] = b->data[i + 1];
	b->size--;
	write(1, "pa\n", 3);
	(*compteur) ++;

}

void	pb(t_stack *a, t_stack *b, int *compteur)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = a->data[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->size--;
	write(1, "pb\n", 3);
	(*compteur) ++;
}
