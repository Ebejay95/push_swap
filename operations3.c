/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:46:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/28 00:48:34 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_dlist **a, t_dlist **b)
{
	ft_dlstrotate(a, 1, 0);
	ft_dlstrotate(b, 1, 0);
	ft_putstr("rrr\n");
	return (1);
}