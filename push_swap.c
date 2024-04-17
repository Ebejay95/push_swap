/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/17 18:25:59 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_dlist **a, t_dlist **b)
{
	int i;
	t_psu cur;
	t_psu cmp;


	i = 0;
	if(ft_dlstsize((*b)) != 0)
		return (0);
	while ((*a) != NULL)
	{
		if((*a)->prev != NULL)
		{
			cur = get_content((*a)->content);
			cmp = get_content((*a)->prev->content);
			if(cur.num_data <= cmp.num_data)
				i++;
		}
		a = &((*a)->next); 
	}
	if(i == 0)
		return (1);
	return (0);
}

void	update_meta(t_dlist **a, t_dlist **b)
{
	int		position;
	t_psu	*tmp;

	position = 0;
	while ((*a) != NULL)
	{
		tmp = (*a)->content;
		tmp->position = position;
		position++;
		a = &((*a)->next);
	}
	position = 0;
	while ((*b) != NULL)
	{
		tmp = (*b)->content;
		tmp->position = position;
		position++;
		b = &((*b)->next);
	}
}

int	get_b_effective_pos(int ref, t_dlist **b)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		position;
	int		pos_max;
	int		valbrd;

	lst = (*b);
	position = 0;
	pos_max = 0;
	valbrd = INT_MIN;
	while (lst != NULL)
	{
		tmp = lst->content;
		if (ref > tmp->num_data && tmp->num_data > valbrd)
		{
			valbrd = tmp->num_data;
			pos_max = tmp->position;
		}
		lst = lst->next;
		position++;
	}
	if(INT_MIN == valbrd)
	{
		return (ft_dlstsize(*b) - 1);
	}
	return (pos_max);
}

int	calc_b_costs(int ref, t_dlist **b)
{
	int len;
	int position;

	len = ft_dlstsize((*b));
	position = get_b_effective_pos(ref, b);
	if (position > (len / 2))
		return (len - position);
	else if (position < (len / 2))
		return (position + 1);
	else if (position == (len / 2) && ft_even(len))
		return ((len / 2));
	else
		return ((len / 2) + 1);
}

void	calc_costs(t_dlist **a, t_dlist **b)
{
	int alen;
	t_psu	*tmp;
	t_dlist *lst;

	lst = (*a);
	alen = ft_dlstsize(lst);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->position > (alen / 2))
			tmp->move_cost_a = alen - tmp->position;
		else if (tmp->position < (alen / 2))
			tmp->move_cost_a = tmp->position + 1;
		else if (tmp->position == (alen / 2) && ft_even(alen))
			tmp->move_cost_a = (alen / 2);
		else
			tmp->move_cost_a = (alen / 2) + 1;
		if(b != NULL)
			tmp->move_cost_b = calc_b_costs(tmp->num_data, b);
		lst = lst->next;
	}
}

void	perform_operations(t_dlist **a, t_dlist **b)
{
	// get cheapest node
	
}

int	sort(t_dlist **a, t_dlist **b)
{
	int operations;

	operations = 0;

	if(!is_sorted(a, b))
	{
		pb(a, b);
		pb(a, b);
		operations = + 2;
	}
	if(!is_sorted(a, b))
	{
		update_meta(a, b);
		calc_costs(a, b);
		//ft_dlstput(a, put_content);
		//write(1, "#\n", 2);
		//ft_dlstput(b, put_content);
		//write(1, "___________________\n", 20);
		perform_operations(a, b);
		operations++;
	}
	return (operations);
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
	ft_putnbr(sort(stack_a, stack_b));
	write(1, "\n", 1);
	return (0);
}
