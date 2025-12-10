/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theomart <theomart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:27:37 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 14:34:05 by theomart         ###   ########.fr       */
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

void	rra(t_stack *a, int c, int *compteur);
void	rrb(t_stack *b, int c, int *compteur);
void	rrr(t_stack *a, t_stack *b, int *compteur);
void	pb(t_stack *a, t_stack *b, int *compteur);
void	pa(t_stack *a, t_stack *b, int *compteur);
void	ss(t_stack *a, t_stack *b, int *compteur);
void	sb(t_stack *b, int c, int *compteur);
void	sa(t_stack *a, int c, int *compteur);
void	rr(t_stack *a, t_stack *b, int *compteur);
void	rrb(t_stack *b, int c, int *compteur);
void	rra(t_stack *a, int c, int *compteur);
void	ra(t_stack *a, int c, int *compteur);
void	rb(t_stack *b, int c, int *compteur);
float	desorder(t_stack *a, int *compteur);

#endif