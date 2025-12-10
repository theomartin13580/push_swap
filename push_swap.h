/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndi-tull <ndi-tull@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:27:37 by ndi-tull          #+#    #+#             */
/*   Updated: 2025/12/10 16:26:16 by ndi-tull         ###   ########.fr       */
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

void	rra(t_stack *a, int c, int *count);
void	rrb(t_stack *b, int c, int *count);
void	rrr(t_stack *a, t_stack *b, int *count);
void	pb(t_stack *a, t_stack *b, int *count);
void	pa(t_stack *a, t_stack *b, int *count);
void	ss(t_stack *a, t_stack *b, int *count);
void	sb(t_stack *b, int c, int *count);
void	sa(t_stack *a, int c, int *count);
void	rr(t_stack *a, t_stack *b, int *count);
void	rrb(t_stack *b, int c, int *count);
void	rra(t_stack *a, int c, int *count);
void	ra(t_stack *a, int c, int *count);
void	rb(t_stack *b, int c, int *count);
float	desorder(t_stack *a);

#endif