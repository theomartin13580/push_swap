/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:18:40 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 11:17:20 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	desorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->data[i] > a->data[j])
				mistakes++;
			total_pairs++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
