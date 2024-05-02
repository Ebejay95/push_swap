/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:20:46 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/02 21:49:54 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	index_walker(t_psu *tmp, t_dlist *lst, t_dlist **smallest)
{
	int	smallv;

	smallv = INT_MAX;
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->index == -1 && tmp->num_data <= smallv)
		{
			smallv = tmp->num_data;
			*smallest = lst;
		}
		lst = lst->next;
	}
}

void	setindexes(t_dlist **a)
{
	int		index;
	t_psu	*tmp;
	t_psu	*smallestitem;
	t_dlist	*lst;
	t_dlist	*smallest;

	index = 0;
	tmp = NULL;
	while (index < (ft_dlstsize((*a))))
	{
		smallest = NULL;
		lst = (*a);
		index_walker(tmp, lst, &smallest);
		if (smallest != NULL)
		{
			smallestitem = smallest->content;
			smallestitem->index = index;
			index++;
		}
	}
}

void	update_distances(t_dlist **a, t_dlist **b)
{
	t_psu	*tmpa;
	t_psu	*tmpb;

	if ((*b) != NULL)
	{
		while ((*a) != NULL)
		{
			tmpb = (*b)->content;
			tmpa = (*a)->content;
			tmpa->distance = tmpa->num_data - tmpb->num_data;
			a = &((*a)->next);
		}
	}
}

void	update_meta(t_dlist **a, t_dlist **b)
{
	int		position;
	t_psu	*tmp;
	t_dlist	*lst;

	tmp = NULL;
	lst = (*a);
	position = 0;
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->position = position;
		position++;
		lst = lst->next;
	}
	position = 0;
	lst = (*b);
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->position = position;
		position++;
		lst = lst->next;
	}
	if ((*a) != NULL && (*b) != NULL)
		update_distances(a, b);
}
