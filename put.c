/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:54:05 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/17 10:04:46 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *set_content(int i)
{
	int *p = malloc(sizeof(int));
	if(!p)
		return (NULL);
	*p = i;
	return (p);
}

int	get_content(void *n)
{
	if(!n)
		return (0);
	return (*(int *)n); 
}

void put_content(void *n)
{
	if(!n)
		return ;
	ft_putnbr(*(int *)n); 
}
