/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:18:13 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/19 13:47:10 by jeberle          ###   ########.fr       */
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
} t_psu;

void	put_content(void *n);
t_psu	get_content(void *n);
void	*set_content(int i);
void	ft_dlstput(t_dlist **lst, void (*t_dlistprint)(void *));
void	put_dlist(t_dlist **lst, void (*t_dlistprint)(void *));

// operations
// -sa (swap a): Swap the first 2 elements at the top of stack a
void	sa(t_dlist **a);
// -sb (swap b): Swap the first 2 elements at the top of stack b.
void	sb(t_dlist **b);
// ss : sa and sb at the same time.
void	ss(t_dlist **a, t_dlist **b);
// pa (push a): Take the first element at the top of b and put it at the top of a.
void	pa(t_dlist **a, t_dlist **b);
// pb (push b): Take the first element at the top of a and put it at the top of b.
void	pb(t_dlist **a, t_dlist **b);
// ra (rotate a): Shift up all elements of stack a by 1.
void	ra(t_dlist **a);
// rb (rotate b): Shift up all elements of stack b by 1.
void	rb(t_dlist **a);
// rr : ra and rb at the same time.
void	rr(t_dlist **a, t_dlist **b);
// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	rra(t_dlist **a);
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
void	rrb(t_dlist **a);
// rrr : rra and rrb at the same time.
void	rrr(t_dlist **a, t_dlist **b);
#endif