/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listhelpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:47:26 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/14 12:30:01 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_dlstsize(t_dlist *dlst)
{
	int	len;

	len = 0;
	while (dlst != NULL)
	{
		dlst = dlst->next;
		len++;
	}
	return (len);
}

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	if (new == NULL || dlst == NULL)
		return ;
	if (*dlst)
   		(*dlst)->prev = new;
	new->prev = NULL;
	new->next = *dlst;
	*dlst = new;
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	while ((*lst)->next != NULL)
		lst = &((*lst)->next);
	(*lst)->next = new;
	new->prev = (*lst);
	new->next = NULL;
}

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void *content(int i)
{
	int *p = malloc(sizeof(int));
	if(!p)
		return (NULL);
	*p = i;
	return (p);
}

void put_content(void *n)
{
	if(!n)
		return ;
	ft_putnbr(*(int *)n); 
}

void	ft_putnbr(int n)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
	}
	nbr = (n % 10) + '0';
	n = n / 10;
	if (n > 0)
		ft_putnbr(n);
	write(1, &nbr, 1);
}
