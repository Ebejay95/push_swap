/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:25:58 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/27 22:57:00 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_dlist **a)
{
	ft_dlstrotate(a, 1, 1);
	ft_putstr("ra\n");
	return (1);
}

int	rb(t_dlist **b)
{
	ft_dlstrotate(b, 1, 1);
	ft_putstr("rb\n");
	return (1);
}

int	rr(t_dlist **a, t_dlist **b)
{
	ft_dlstrotate(a, 1, 1);
	ft_dlstrotate(b, 1, 1);
	ft_putstr("rr\n");
	return (1);
}

int	rra(t_dlist **a)
{
	ft_dlstrotate(a, 1, 0);
	ft_putstr("rra\n");
	return (1);
}

int	rrb(t_dlist **b)
{
	ft_dlstrotate(b, 1, 0);
	ft_putstr("rrb\n");
	return (1);
}
