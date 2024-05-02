/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/05/02 17:21:04 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;
	t_dlist	*stackanuller;
	t_dlist	*stackbnuller;
	int		error;

	error = 0;
	stackanuller = NULL;
	stackbnuller = NULL;
	stack_a = &stackanuller;
	stack_b = &stackbnuller;
	fill_initial(stack_a, argc, argv, &error);
	if (error > 0)
	{
		free_stacks(stack_a, stack_b);
		ft_putstr("Error\n");
		return (0);
	}
	sort(stack_a, stack_b);
	update_meta(stack_a, stack_b);
	if (get_pos_max(stack_a) != (ft_dlstsize((*stack_a)) - 1))
		shift_max_down(stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
