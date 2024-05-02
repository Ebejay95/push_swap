/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:19:18 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/02 21:49:54 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

t_dlist	*get_max_node(t_dlist **stack)
{
	t_dlist	*current;
	t_dlist	*maxnode;
	t_psu	*tmp;
	int		max;

	max = INT_MIN;
	maxnode = NULL;
	current = (*stack);
	while (current != NULL)
	{
		tmp = current->content;
		if (tmp->num_data == INT_MAX)
			return (current);
		if (tmp->num_data > max)
		{
			max = tmp->num_data;
			maxnode = current;
		}
		current = current->next;
	}
	return (maxnode);
}

int	get_pos_min(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist	*lst;
	int		pos_min;
	int		valbrd;

	lst = (*stack);
	pos_min = 0;
	valbrd = INT_MAX;
	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->num_data < valbrd)
		{
			valbrd = tmp->num_data;
			pos_min = tmp->position;
		}
		lst = lst->next;
	}
	return (pos_min);
}

int	get_pos_max(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist	*lst;
	int		pos_max;
	int		valbrd;

	lst = (*stack);
	pos_max = 0;
	valbrd = INT_MIN;
	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->num_data == INT_MAX)
			return (tmp->position);
		if (tmp->num_data > valbrd)
		{
			valbrd = tmp->num_data;
			pos_max = tmp->position;
		}
		lst = lst->next;
	}
	return (pos_max);
}

int	get_indx_min(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist	*lst;
	int		valbrd;

	lst = (*stack);
	valbrd = INT_MAX;
	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->index < valbrd)
		{
			valbrd = tmp->index;
		}
		lst = lst->next;
	}
	return (valbrd);
}

int	is_sorted(t_dlist **a, t_dlist **b)
{
	int		i;
	t_psu	cur;
	t_psu	cmp;

	i = 0;
	if (ft_dlstsize((*b)) != 0)
		return (0);
	while ((*a) != NULL)
	{
		if ((*a)->prev != NULL)
		{
			cur = n_cnt((*a)->content);
			cmp = n_cnt((*a)->prev->content);
			if (cur.num_data <= cmp.num_data)
				i++;
		}
		a = &((*a)->next);
	}
	if (i == 0)
		return (1);
	return (0);
}
