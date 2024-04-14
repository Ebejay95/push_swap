/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:36:40 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/14 12:31:08 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putdlst(t_dlist **lst, void (*t_dlistprint)(void *))
{
	t_dlist *tmp = *lst;
	if (lst == NULL || *lst == NULL)
	{
		return ;
	}
	while (tmp != NULL)
	{
		t_dlistprint(tmp->content);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}