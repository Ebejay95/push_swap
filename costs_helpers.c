/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:04:09 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 03:02:01 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_target(int smallestgreater, int found_smaller, t_dlist **a)
{
	int	target;

	target = -1;
	if (smallestgreater != INT_MAX)
		target = smallestgreater;
	else if (found_smaller)
		target = get_indx_min(a);
	return (target);
}

t_psu	*set_b_cost(t_psu *tmp, t_dlist *lst)
{
	if (tmp->position > (ft_dlstsize(lst) / 2))
		tmp->move_cost_b = 0 - (ft_dlstsize(lst) - tmp->position);
	else if (tmp->position < (ft_dlstsize(lst) / 2))
		tmp->move_cost_b = tmp->position;
	else if (ft_even(ft_dlstsize(lst)))
		tmp->move_cost_b = (ft_dlstsize(lst) / 2);
	else
		tmp->move_cost_b = tmp->position;
	return (tmp);
}
