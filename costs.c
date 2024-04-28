/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:21:42 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 03:02:26 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_possible_ndx(int current_index, t_dlist **a)
{
	t_dlist	*current;
	int		smallestgreater;
	int		found_smaller;
	int		current_index_value;

	current = (*a);
	smallestgreater = INT_MAX;
	found_smaller = 0;
	current_index_value = 0;
	while (current != NULL)
	{
		current_index_value = n_cnt(current->content).index;
		if (current_index < current_index_value)
		{
			if (current_index_value < smallestgreater)
			{
				smallestgreater = current_index_value;
				found_smaller = 0;
			}
		}
		else
			found_smaller = 1;
		current = current->next;
	}
	return (make_target(smallestgreater, found_smaller, a));
}

int	efpos(int position, int size)
{
	if (position > (size / 2))
		return ((-1) * (size - position));
	else
		return (position);
}

int	getposbydex(int index, t_dlist **a)
{
	t_dlist	*cur;
	t_psu	*tmp;

	cur = (*a);
	while (cur != NULL)
	{
		tmp = cur->content;
		if (index == tmp->index)
			return (efpos(n_cnt(cur->content).position, ft_dlstsize((*a))));
		cur = cur->next;
	}
	return (efpos(n_cnt((*a)->content).position, ft_dlstsize((*a))));
}

void	calculate_costs(t_dlist **a, t_dlist **b)
{
	t_psu	ref;
	t_psu	*tmp;
	t_dlist	*lst;
	int		target_distance;
	int		targetpos;

	ref = n_cnt((*a)->content);
	lst = (*b);
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->distance = ft_abs(ref.index - tmp->index);
		tmp = set_b_cost(tmp, (*b));
		target_distance = get_next_possible_ndx(n_cnt(lst->content).index, a);
		targetpos = getposbydex(target_distance, a);
		tmp->move_cost_a = targetpos;
		tmp->abs_cost = ft_abs(tmp->move_cost_a) + ft_abs(tmp->move_cost_b);
		lst = lst->next;
	}
}

t_dlist	*get_cheapest_node(t_dlist **a, t_dlist **b)
{
	t_psu	tmp;
	t_dlist	*current;
	t_dlist	*cheapest;
	int		costref;

	cheapest = NULL;
	costref = INT_MAX;
	current = (*b);
	while (current != NULL)
	{
		tmp = n_cnt(current->content);
		if (can_insert(a, &tmp))
		{
			if (tmp.abs_cost < costref)
			{
				costref = tmp.abs_cost;
				cheapest = current;
			}
		}
		current = current->next;
	}
	return (cheapest);
}
