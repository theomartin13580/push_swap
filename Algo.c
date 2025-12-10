/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:58:02 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 11:22:25 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_is_the_minimum(t_stack *a)
{
	int	i;
	int	min;
	int	index;

	i = 1;
	min = a->data[0];
	while (i < a->size)
	{
		if (a->data[i] > a->data[min])
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
}