/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:25:56 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/25 00:20:40 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -sa (swap a): Swap the first 2 elements at the top of stack a
int	sa(t_dlist **a)
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
	ft_putstr("sa\n");
	return (1);
}

// -sb (swap b): Swap the first 2 elements at the top of stack b.
int	sb(t_dlist **b)
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
	ft_putstr("sb\n");
	return (1);
}

// ss : sa and sb at the same time.
int	ss(t_dlist **a, t_dlist **b)
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
	ft_putstr("ss\n");
	return (1);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
int	pa(t_dlist **a, t_dlist **b)
{
	t_dlist *tmp;
	if (*b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		ft_dlstadd_front(a, tmp);
	}
	ft_putstr("pa\n");
	return (1);
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
int	pb(t_dlist **a, t_dlist **b)
{
	t_dlist *tmp;
	if (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		ft_dlstadd_front(b, tmp);
	}
	ft_putstr("pb\n");
	return (1);
}

// ra (rotate a): Shift up all elements of stack a by 1.
int	ra(t_dlist **a)
{
	ft_dlstrotate(a, 1, 1);
	ft_putstr("ra\n");
	return (1);
}

// rb (rotate b): Shift up all elements of stack b by 1.
int	rb(t_dlist **b)
{
	ft_dlstrotate(b, 1, 1);
	ft_putstr("rb\n");
	return (1);
}

// rr : ra and rb at the same time.
int	rr(t_dlist **a, t_dlist **b)
{
	ft_dlstrotate(a, 1, 1);
	ft_dlstrotate(b, 1, 1);
	ft_putstr("rr\n");
	return (1);
}

// ra (rotate a): Shift up all elements of stack a by 1.
int	rra(t_dlist **a)
{
	ft_dlstrotate(a, 1, 0);
	ft_putstr("rra\n");
	return (1);
}

// rb (rotate b): Shift up all elements of stack b by 1.
int	rrb(t_dlist **b)
{
	ft_dlstrotate(b, 1, 0);
	ft_putstr("rrb\n");
	return (1);
}

// rrr : ra and rb at the same time.
int	rrr(t_dlist **a, t_dlist **b)
{
	ft_dlstrotate(a, 1, 0);
	ft_dlstrotate(b, 1, 0);
	ft_putstr("rrr\n");
	return (1);
}