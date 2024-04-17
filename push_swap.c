/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/17 10:18:14 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_dlist **a, t_dlist **b)
{
	int i;

	i = 0;
	if(ft_dlstsize((*b)) != 0)
		return (0);
	while ((*a) != NULL)
	{
		if((*a)->prev != NULL)
		{
			if(get_content((*a)->content) < get_content((*a)->prev->content))
				i++;
		}
		a = &((*a)->next); 
	}
	if(i == 0)
		return (1);
	return (0);
}

int validate_arg(char *arg)
{
	int i;

	i = 0;
	if (*arg == 43 || *arg == 45)
	{
		printf("waspre\n");
		i++;
	}
	if(ft_isdigit(arg[i]))
		return (0);
	return (1);
}

void	fill_initial(t_dlist **stack_a, int argc, char **argv, int *e)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if(validate_arg(argv[i]) != 0)
			(*e)++;
		ft_dlstadd_back(stack_a, ft_dlstnew(set_content(ft_atoi(argv[i]))));
		i++;
	}
}

int main(int argc, char **argv)
{
	t_dlist **stack_a;
	t_dlist **stack_b;
	t_dlist *stackanuller;
	t_dlist *stackbnuller;
	int error;

	error = 0;
	stackanuller = NULL;
	stackbnuller = NULL;
	stack_a = &stackanuller;
	stack_b = &stackbnuller;
	fill_initial(stack_a, argc, argv, &error);
	if(ft_dlstsize((*stack_a)) < 2 && error == 0)
	{
		write(1, "0\n", 2);
		return (0);
	} else if(error > 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("%i\n", is_sorted(stack_a, stack_b));
	return (0);
}
