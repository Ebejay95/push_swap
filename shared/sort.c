/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:32:06 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/02 21:49:54 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	sort_three(t_dlist **a)
{
	t_dlist	*maxnode;

	maxnode = get_max_node(a);
	if (maxnode == (*a))
		ra(a);
	else if (maxnode == (*a)->next)
		rra(a);
	if (n_cnt((*a)->content).num_data > n_cnt((*a)->next->content).num_data)
		sa(a);
}

void	sort_four(t_dlist **a, t_dlist **b)
{
	update_meta(a, b);
	shift_min_up(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	update_meta(a, b);
	if (get_pos_max(a) != (ft_dlstsize((*a)) - 1))
		shift_max_down(a);
}

void	sort_five(t_dlist **a, t_dlist **b)
{
	update_meta(a, b);
	shift_min_up(a);
	pb(a, b);
	update_meta(a, b);
	shift_min_up(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	update_meta(a, b);
	if (get_pos_max(a) != (ft_dlstsize((*a)) - 1))
		shift_max_down(a);
}

void	sort_more(t_dlist **a, t_dlist **b, int sep)
{
	while (ft_dlstsize((*a)) > 0)
	{
		if (n_cnt((*a)->content).index < sep)
		{
			pb(a, b);
			sep++;
		}
		else
			ra(a);
	}
	while (ft_dlstsize((*a)) > 3)
	{
		pb(a, b);
	}
	pa(a, b);
	pa(a, b);
	while (ft_dlstsize((*b)) != 0)
	{
		update_meta(a, b);
		calculate_costs(a, b);
		perform_pb_rotations(a, b, get_cheapest_node(a, b));
		pa(a, b);
	}
}

void	sort(t_dlist **a, t_dlist **b)
{
	int	sep;

	sep = (ft_dlstsize((*a)) / 3);
	setindexes(a);
	if (!is_sorted(a, b) && ft_dlstsize((*a)) == 2)
	{
		update_meta(a, b);
		if (n_cnt((*a)->content).num_data > n_cnt((*a)->next->content).num_data)
			sa(a);
	}
	else if (!is_sorted(a, b) && ft_dlstsize((*a)) == 3)
		sort_three(a);
	else if (!is_sorted(a, b) && ft_dlstsize((*a)) == 4)
		sort_four(a, b);
	else if (!is_sorted(a, b) && ft_dlstsize((*a)) == 5)
		sort_five(a, b);
	else if (!is_sorted(a, b))
		sort_more(a, b, sep);
	update_meta(a, b);
	if (get_pos_max(a) != (ft_dlstsize((*a)) - 1))
		shift_max_down(a);
}
