/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/28 01:39:13 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ret_and_put(int ret, char *put)
{
	ft_putstr(put);
	return (ret);
}

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
	if (ft_dlstsize((*stack_a)) < 2 && error == 0)
		ret_and_put(0, "0\n");
	if (error > 0)
		ret_and_put(0, "Error\n");
	sort(stack_a, stack_b);
	update_meta(stack_a, stack_b);
	if (get_pos_max(stack_a) != (ft_dlstsize((*stack_a)) - 1))
		shift_max_down(stack_b);
	return (0);
}
