/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:54:05 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/19 13:47:14 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *set_content(int n)
{
	t_psu *p = ft_calloc(1,sizeof(t_psu));
	if(!p)
		return (NULL);
	p->num_data = n;
	p->move_cost_a = 0;
	p->move_cost_b = 0;
	p->position = 0;
	p->distance = 0;
	p->abs_cost = 0;
	return (p);
}

t_psu	get_content(void *n)
{
	return (*(t_psu *)n); 
}

void put_content(void *n)
{
	t_psu *toput;

	if(!n)
		return ;
	toput = (t_psu *)n;
	write (1, "num_data: ", 10);
	ft_putnbr(toput->num_data);
	write (1, " cost: ", 7);
	ft_putnbr(toput->move_cost_a);
	write (1, " ", 1);
	ft_putnbr(toput->move_cost_b);
	write (1, " ", 1);
	ft_putnbr(toput->abs_cost);
	write (1, " dist: ", 7);
	ft_putnbr(toput->distance);
	//write (1, "num_data: ", 10);
	//ft_putnbr(toput->num_data);
	//write (1, "\nmove_cost_a: ", 14);
	//ft_putnbr(toput->move_cost_a);
	//write (1, "\nmove_cost_b: ", 14);
	//ft_putnbr(toput->move_cost_b);
	//write (1, "\nposition: ", 11);
	//ft_putnbr(toput->position);
	//write (1, "\nabs_cost: ", 19);
	//ft_putnbr(toput->abs_cost);
	//write (1, "\n", 1);
}
