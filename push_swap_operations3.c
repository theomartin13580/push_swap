/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:37:17 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 14:38:25 by theomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int c, int *compteur)
{
	int	i;
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = tmp;
	if (c == 1)
	{
		write(1, "rra\n", 4);
		(*compteur) ++;
	}
}

void	rrb(t_stack *b, int c, int *compteur)
{
	int	i;
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->data[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = tmp;
	if (c == 1)
	{
		write(1, "rrb\n", 4);
		(*compteur) ++;
	}
}

void	rrr(t_stack *a, t_stack *b, int *compteur)
{
	rra(a, 0, compteur);
	rrb(b, 0, compteur);
	write(1, "rrr\n", 4);
	(*compteur) ++;

}
