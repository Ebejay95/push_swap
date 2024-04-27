/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationshelper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:35:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 01:26:26 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	non_connected_a_operations(t_dlist **a, t_dlist *cheapest)
{
	int		adirection;
	int		aop_count;

	aop_count = ft_abs(n_cnt(cheapest->content).move_cost_a);
	adirection = ft_ispos(n_cnt(cheapest->content).move_cost_a);
	while (aop_count > 0)
	{
		if (adirection)
			ra(a);
		else
			rra(a);
		aop_count--;
	}
}

void	non_connected_b_operations(t_dlist **b, t_dlist *cheapest)
{
	int		bdirection;
	int		bop_count;

	bop_count = ft_abs(n_cnt(cheapest->content).move_cost_b);
	bdirection = ft_ispos(n_cnt(cheapest->content).move_cost_b);
	while (bop_count > 0)
	{
		if (bdirection)
			rb(b);
		else
			rrb(b);
		bop_count--;
	}
}

void	perform_pb_rotations(t_dlist **a, t_dlist **b, t_dlist *cheapest)
{
	int		aop_count;
	int		bop_count;
	int		mc;
	t_psu	cc;

	cc = n_cnt(cheapest->content);
	aop_count = ft_abs(cc.move_cost_a);
	bop_count = ft_abs(cc.move_cost_b);
	if (aop_count < bop_count)
		mc = aop_count;
	else
		mc = bop_count;
	while (mc > 0 && ft_ispos(cc.move_cost_a) == ft_ispos(cc.move_cost_b))
	{
		if (ft_ispos(cc.move_cost_a))
			rr(a, b);
		else
			rrr(a, b);
		mc--;
		aop_count--;
		bop_count--;
	}
	non_connected_a_operations(a, cheapest);
	non_connected_b_operations(b, cheapest);
}
