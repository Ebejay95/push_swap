/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationshelper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:35:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/02 21:49:54 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	non_connected_a_operations(t_dlist **a, int aop_count, int adirection)
{
	while (aop_count > 0)
	{
		if (adirection)
			ra(a);
		else
			rra(a);
		aop_count--;
	}
}

void	non_connected_b_operations(t_dlist **b, int bop_count, int bdirection)
{
	while (bop_count > 0)
	{
		if (bdirection)
			rb(b);
		else
			rrb(b);
		bop_count--;
	}
}

int	get_minopcount(int aop_count, int bop_count)
{
	if (aop_count < bop_count)
	{
		return (aop_count);
	}
	return (bop_count);
}

void	perform_pb_rotations(t_dlist **a, t_dlist **b, t_dlist *cheapest)
{
	int		adirection;
	int		aop_count;
	int		bdirection;
	int		bop_count;
	int		minopcount;

	aop_count = ft_abs(n_cnt(cheapest->content).move_cost_a);
	adirection = ft_ispos(n_cnt(cheapest->content).move_cost_a);
	bop_count = ft_abs(n_cnt(cheapest->content).move_cost_b);
	bdirection = ft_ispos(n_cnt(cheapest->content).move_cost_b);
	minopcount = get_minopcount(aop_count, bop_count);
	while (minopcount > 0 && adirection == bdirection)
	{
		if (adirection)
			rr(a, b);
		else
			rrr(a, b);
		minopcount--;
		aop_count--;
		bop_count--;
	}
	non_connected_a_operations(a, aop_count, adirection);
	non_connected_b_operations(b, bop_count, bdirection);
}
