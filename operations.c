/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:25:56 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/16 21:43:54 by jonathanebe      ###   ########.fr       */
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

// ss : sa and sb at the same time.
void	ss(t_dlist **a, t_dlist **b)
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
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
void	pa(t_dlist **a, t_dlist **b)
{
	t_dlist *tmp;
	if (*b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		ft_dlstadd_front(a, tmp);
	}
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
void	pb(t_dlist **a, t_dlist **b)
{
	t_dlist *tmp;
	if (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		ft_dlstadd_front(b, tmp);
	}
}

// ra (rotate a): Shift up all elements of stack a by 1.
void	ra(t_dlist **a)
{
	ft_dlstrotate(a, 1, 0);
}

// rb (rotate b): Shift up all elements of stack b by 1.
void	rb(t_dlist **b)
{
	ft_dlstrotate(b, 1, 0);
}

// rr : ra and rb at the same time.
void	rr(t_dlist **a, t_dlist **b)
{
	ft_dlstrotate(a, 1, 0);
	ft_dlstrotate(b, 1, 0);
}

// ra (rotate a): Shift up all elements of stack a by 1.
void	rra(t_dlist **a)
{
	ft_dlstrotate(a, 1, 1);
}

// rb (rotate b): Shift up all elements of stack b by 1.
void	rrb(t_dlist **b)
{
	ft_dlstrotate(b, 1, 1);
}

// rrr : ra and rb at the same time.
void	rrr(t_dlist **a, t_dlist **b)
{
	ft_dlstrotate(a, 1, 1);
	ft_dlstrotate(b, 1, 1);
}