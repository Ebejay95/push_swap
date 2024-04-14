/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:25:56 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/14 11:20:26 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -sa (swap a): Swap the first 2 elements at the top of stack a
void	sa(t_dlist **a)
{
	t_dlist *tmp;
	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		tmp->prev = NULL;
		if((*a)->next)
			(*a)->next->prev = *a;
		(*a)->prev = tmp;
		(*a) = tmp;
	}
}

// -sb (swap b): Swap the first 2 elements at the top of stack b.
void	sb(t_dlist **b)
{
	t_dlist *tmp;
	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		tmp->prev = NULL;
		if((*b)->next)
			(*b)->next->prev = *b;
		(*b)->prev = tmp;
		(*b) = tmp;
	}
}
