/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psu_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:54:05 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/29 23:52:05 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	put_content(void *n)
// {
// 	t_psu	*toput;

// 	if (!n)
// 		return ;
// 	toput = (t_psu *)n;
// 	write (1, "num_data: ", 10);
// 	ft_putnbr(toput->num_data);
// 	write (1, " pos: ", 6);
// 	ft_putnbr(toput->position);
// 	write (1, " cost: ", 7);
// 	ft_putnbr(toput->move_cost_a);
// 	write (1, " ", 1);
// 	ft_putnbr(toput->move_cost_b);
// 	write (1, " ", 1);
// 	ft_putnbr(toput->abs_cost);
// 	write (1, " dist: ", 7);
// 	ft_putnbr(toput->distance);
// 	write (1, " ndx: ", 7);
// 	ft_putnbr(toput->index);
// }

// void	put_short(void *n)
// {
// 	t_psu	*toput;

// 	if (!n)
// 		return ;
// 	toput = (t_psu *)n;
// 	ft_putnbr(toput->num_data);
// }

void	*set_content(int n)
{
	t_psu	*p;

	p = ft_calloc(1, sizeof(t_psu));
	if (!p)
		return (NULL);
	p->num_data = n;
	p->move_cost_a = 0;
	p->move_cost_b = 0;
	p->position = 0;
	p->distance = 0;
	p->abs_cost = 0;
	p->index = -1;
	return (p);
}

t_psu	n_cnt(void *n)
{
	return (*(t_psu *)n);
}

void	del_content(void *n)
{
	if (n)
	{
		free(n);
		n = NULL;
	}
}

int	cmp_c(void *a, void *b)
{
	t_psu	atpsu;
	t_psu	btpsu;

	atpsu = *(t_psu *)a;
	btpsu = *(t_psu *)b;
	return (atpsu.num_data != btpsu.num_data);
}
