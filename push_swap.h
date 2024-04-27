/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:18:13 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 01:33:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

// push swap unit
typedef struct s_psu
{
	int	num_data;
	int	move_cost_a;
	int	move_cost_b;
	int	position;
	int	distance;
	int	abs_cost;
	int	index;
}	t_psu;

void	setindexes(t_dlist **a);
int		is_sorted(t_dlist **a, t_dlist **b);
t_dlist	*get_cheapest_node(t_dlist **a, t_dlist **b);
void	perform_pb_rotations(t_dlist **a, t_dlist **b, t_dlist *cheapest);
void	calculate_costs(t_dlist **a, t_dlist **b);
void	shift_min_up(t_dlist **a);
t_dlist	*get_max_node(t_dlist **stack);
int		get_pos_min(t_dlist **stack);
int		get_pos_max(t_dlist **stack);
void	shift_max_down(t_dlist **a);
void	update_meta(t_dlist **a, t_dlist **b);
void	sort(t_dlist **a, t_dlist **b);
void	fill_initial(t_dlist **stack_a, int argc, char **argv, int *e);
int		can_insert(t_dlist **a, t_psu *b_content);
t_psu	*set_b_cost(t_psu *tmp, t_dlist *lst);
int		get_indx_min(t_dlist **stack);
void	ch_as_next(int cur_ndx, int cur_ndx_val, int *fnd_sm, int *sm);
t_psu	n_cnt(void *n);
void	*set_content(int i);
void	put_dlist(t_dlist **lst, void (*t_dlistprint)(void *));

// operations
int		sa(t_dlist **a);
int		sb(t_dlist **b);
int		ss(t_dlist **a, t_dlist **b);
int		pa(t_dlist **a, t_dlist **b);
int		pb(t_dlist **a, t_dlist **b);
int		ra(t_dlist **a);
int		rb(t_dlist **a);
int		rr(t_dlist **a, t_dlist **b);
int		rra(t_dlist **a);
int		rrb(t_dlist **a);
int		rrr(t_dlist **a, t_dlist **b);
#endif