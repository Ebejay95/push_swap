/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:25:56 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/05/02 21:49:54 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	sa(t_dlist **a)
{
	t_dlist	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		tmp->prev = NULL;
		if ((*a)->next)
			(*a)->next->prev = *a;
		(*a)->prev = tmp;
		(*a) = tmp;
	}
	ft_putstr("sa\n");
	return (1);
}

int	sb(t_dlist **b)
{
	t_dlist	*tmp;

	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		tmp->prev = NULL;
		if ((*b)->next)
			(*b)->next->prev = *b;
		(*b)->prev = tmp;
		(*b) = tmp;
	}
	ft_putstr("sb\n");
	return (1);
}

int	ss(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;

	if (*a != NULL && (*a)->next != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		tmp->prev = NULL;
		if ((*a)->next)
			(*a)->next->prev = *a;
		(*a)->prev = tmp;
		(*a) = tmp;
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		tmp->prev = NULL;
		if ((*b)->next)
			(*b)->next->prev = *b;
		(*b)->prev = tmp;
		(*b) = tmp;
	}
	ft_putstr("ss\n");
	return (1);
}

int	pa(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;

	if (*b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		ft_dlstadd_front(a, tmp);
	}
	ft_putstr("pa\n");
	return (1);
}

int	pb(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;

	if (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		ft_dlstadd_front(b, tmp);
	}
	ft_putstr("pb\n");
	return (1);
}
