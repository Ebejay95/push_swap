/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzers2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:28:33 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/02 21:49:54 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	can_insert(t_dlist **a, t_psu *b_content)
{
	t_dlist	*current_a;
	int		data;
	int		current_data;
	int		next_data;

	current_a = (*a);
	data = b_content->num_data;
	if (!current_a || data <= n_cnt(current_a->content).num_data)
		return (1);
	while (current_a->next != NULL)
	{
		current_data = n_cnt(current_a->content).num_data;
		next_data = n_cnt(current_a->next->content).num_data;
		if (current_data <= data && data <= next_data)
			return (1);
		current_a = current_a->next;
	}
	if (data >= n_cnt(current_a->content).num_data)
		return (1);
	return (0);
}
