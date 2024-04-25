/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:18:13 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/25 17:33:15 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "./libft/libft.h"

// push swap unit
typedef struct s_psu
{
	int num_data;
	int move_cost_a;
	int move_cost_b;
	int position;
	int distance;
	int abs_cost;
	int index;
} t_psu;

void	put_content(void *n);
void	put_short(void *n);
t_psu	get_content(void *n);
void	*set_content(int i);
void	put_dlist(t_dlist **lst, void (*t_dlistprint)(void *));

// operations
// -sa (swap a): Swap the first 2 elements at the top of stack a
int	sa(t_dlist **a);
// -sb (swap b): Swap the first 2 elements at the top of stack b.
int	sb(t_dlist **b);
// ss : sa and sb at the same time.
int	ss(t_dlist **a, t_dlist **b);
// pa (push a): Take the first element at the top of b and put it at the top of a.
int	pa(t_dlist **a, t_dlist **b);
// pb (push b): Take the first element at the top of a and put it at the top of b.
int	pb(t_dlist **a, t_dlist **b);
// ra (rotate a): Shift up all elements of stack a by 1.
int	ra(t_dlist **a);
// rb (rotate b): Shift up all elements of stack b by 1.
int	rb(t_dlist **a);
// rr : ra and rb at the same time.
int	rr(t_dlist **a, t_dlist **b);
// rra (reverse rotate a): Shift down all elements of stack a by 1.
int	rra(t_dlist **a);
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
int	rrb(t_dlist **a);
// rrr : rra and rrb at the same time.
int	rrr(t_dlist **a, t_dlist **b);
#endif