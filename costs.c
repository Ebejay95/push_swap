/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:21:42 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 01:17:11 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_possible_ndx(int curndx, t_dlist **a)
{
	t_dlist	*current;
	int		target;
	int		smallgreater;
	int		fnd_sm;
	int		curndx_value;

	current = (*a);
	target = -1;
	smallgreater = INT_MAX;
	fnd_sm = 0;
	curndx_value = 0;
	while (current != NULL)
	{
		curndx_value = n_cnt(current->content).index;
		ch_as_next(curndx, curndx_value, &fnd_sm, &smallgreater);
		current = current->next;
	}
	if (smallgreater != INT_MAX)
		target = smallgreater;
	else if (fnd_sm)
		target = get_indx_min(a);
	return (target);
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
