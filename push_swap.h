/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:27:37 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/09 18:08:18 by ndi-tull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	int *data;    // Tableau de int
	int size;     // Nombre d'elements
	int capacity; // Taille max que le tableau peut avoir
}		t_stack;

void	rra(t_stack *a, int c);
void	rrb(t_stack *b, int c);
void	rrr(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	sb(t_stack *b, int c);
void	sa(t_stack *a, int c);
void	rr(t_stack *a, t_stack *b);
void	rrb(t_stack *b, int c);
void	rra(t_stack *a, int c);
float	desorder(t_stack *a);

#endif