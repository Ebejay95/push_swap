/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:30:24 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 00:30:47 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_max_down(t_dlist **a)
{
	int	pos_max;
	int	moves;

	pos_max = get_pos_max(a);
	if (pos_max == -1)
		return ;
	if (pos_max > (ft_dlstsize((*a)) / 2))
	{
		moves = ft_dlstsize((*a)) - pos_max - 1;
		while (moves > 0)
		{
			rra(a);
			moves--;
		}
	}
	else
	{
		moves = pos_max + 1;
		while (moves > 0)
		{
			ra(a);
			moves--;
		}
	}
}

void	shift_min_up(t_dlist **a)
{
	int	pos_min;
	int	moves;

	pos_min = get_pos_min(a);
	if (pos_min > (ft_dlstsize((*a)) / 2))
	{
		moves = ft_dlstsize((*a)) - pos_min;
		while (moves > 0)
		{
			rra(a);
			moves--;
		}
	}
	else
	{
		moves = pos_min;
		while (moves > 0)
		{
			ra(a);
			moves--;
		}
	}
}
