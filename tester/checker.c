/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:53:19 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/05/03 13:32:51 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	print_result(int state)
{
	if (state == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

void	perform_check_op(t_dlist **a, t_dlist **b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b);
}

int	check_sorting(t_dlist **a, t_dlist **b)
{
	char	*operation;
	int		linecount;

	operation = NULL;
	linecount = 0;
	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		perform_check_op(a, b, operation);
		linecount++;
		free(operation);
	}
	return (is_sorted(a, b));
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
	if (error > 0)
	{
		free_stacks(stack_a, stack_b);
		ft_putstr("Error\n");
		return (0);
	}
	print_result(check_sorting(stack_a, stack_b));
	free_stacks(stack_a, stack_b);
	return (0);
}
