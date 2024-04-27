/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:04:09 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 01:32:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_as_next(int cur_ndx, int cur_ndx_val, int *fnd_sm, int *sm)
{
	if (cur_ndx < cur_ndx_val)
	{
		if (cur_ndx_val < *sm)
		{
			*sm = cur_ndx_val;
			*fnd_sm = 0;
		}
	}
	else
		*fnd_sm = 1;
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
