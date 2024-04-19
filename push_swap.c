/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/19 15:53:39 by jeberle          ###   ########.fr       */
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

void	update_distances(t_dlist **a, t_dlist **b)
{
	t_psu	*tmpa;
	t_psu	*tmpb;

	if ((*b) != NULL)
	{
		while ((*a) != NULL)
		{
			tmpb = (*b)->content;
			tmpa = (*a)->content;
			tmpa->distance = tmpa->num_data - tmpb->num_data;
			a = &((*a)->next);
		}
	}
}

void	update_meta(t_dlist **a, t_dlist **b)
{
	int		position;
	t_psu	*tmp;
	t_dlist *lst;

	lst = (*a);
	position = 0;
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->position = position;
		position++;
		lst = lst->next;
	}
	position = 0;
	update_distances(a,b);
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
		return (ft_dlstsize(*b) - 1);
	return (pos_max);
}

int	calc_b_costs(int ref, t_dlist **b)
{
	int len;
	int position;

	len = ft_dlstsize((*b));
	position = get_b_effective_pos(ref, b);
	if (position > (len - position))
		return ((len - position) * (-1));
	else 
		return (position);
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
			tmp->move_cost_a = 0 - (alen - tmp->position);
		else if (tmp->position < (alen / 2))
			tmp->move_cost_a = tmp->position;
		else
		{
			if (ft_even(alen))
				tmp->move_cost_a = (alen / 2);
			else
				tmp->move_cost_a = tmp->position;
		}
		if(b != NULL)
			tmp->move_cost_b = calc_b_costs(tmp->num_data, b);
		tmp->abs_cost = ft_abs(tmp->move_cost_b) + ft_abs(tmp->move_cost_a);
		lst = lst->next;
	}
}

t_dlist *get_cheapest_node(t_dlist **a)
{
	t_psu tmp;
	t_dlist *current;
	t_dlist *cheapest;
	int costref;

	cheapest = NULL;
	costref = INT_MAX;
	current = (*a);
	while (current != NULL)
	{
		tmp = get_content(current->content);
		if(tmp.abs_cost <= costref)
		{
			costref = tmp.abs_cost;
			if(cheapest && get_content(cheapest->content).distance > 0)
			{
				if(get_content(cheapest->content).distance > tmp.distance)
					cheapest = current;
			}
			else
				cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}


//void	perform_operations(t_dlist **a, t_dlist **b)
void	perform_operations(t_dlist **a)
{
	t_dlist *cheapest;
	int		direction;
	int		op_count;

	cheapest = get_cheapest_node(a);
	printf("CHEAP: %i\n", get_content(cheapest->content).num_data);
	op_count = ft_abs(get_content(cheapest->content).move_cost_a);
	direction = ft_ispos(get_content(cheapest->content).move_cost_a);
	printf("ROT A: %i\n", op_count);
	printf("DIR A: %i\n", direction);
	while (op_count > 0)
	{
		if(direction)
			printf("ra\n"); //rb(b);
		else
			printf("rra\n"); //rrb(b);
		op_count--;
	}
	op_count = ft_abs(get_content(cheapest->content).move_cost_b);
	direction = ft_ispos(get_content(cheapest->content).move_cost_b);
	printf("ROT B: %i\n", op_count);
	printf("DIR B: %i\n", direction);
	while (op_count > 0)
	{
		if(direction)
			printf("rb\n"); //rb(b);
		else
			printf("rrb\n"); //rrb(b);
		op_count--;
	}
}

int	sort(t_dlist **a, t_dlist **b)
{
	int operations;

	operations = 0;

	if(!is_sorted(a, b))
	{
		pb(a, b);
		pb(a, b);
		ft_dlstput(a, put_content);
		write(1, "#\n", 2);
		ft_dlstput(b, put_content);
		write(1, "___________________\n", 20);
		rb(b);
		ft_dlstput(a, put_content);
		write(1, "#\n", 2);
		ft_dlstput(b, put_content);
		write(1, "___________________\n", 20);
		operations = + 2;
	}
	if(!is_sorted(a, b))
	{
		update_meta(a, b);
		calc_costs(a, b);
		ft_dlstput(a, put_content);
		write(1, "#\n", 2);
		ft_dlstput(b, put_content);
		write(1, "___________________\n", 20);
		//perform_operations(a);
		//ft_dlstput(a, put_content);
		//write(1, "#\n", 2);
		//ft_dlstput(b, put_content);
		//write(1, "___________________\n", 20);
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
