/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/24 23:50:11 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos_min(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		pos_min;
	int		valbrd;
	lst = (*stack);
	pos_min = 0;
	valbrd = INT_MAX;

	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->num_data < valbrd)
		{
			valbrd = tmp->num_data;
			pos_min = tmp->position;
		}
		lst = lst->next;
	}
	return (pos_min);
}

int	get_pos_max(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		pos_max;
	int		valbrd;
	lst = (*stack);
	pos_max = 0;
	valbrd = INT_MIN;

	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->num_data > valbrd)
		{
			valbrd = tmp->num_data;
			pos_max = tmp->position;
		}
		lst = lst->next;
	}
	return (pos_max);
}

int	get_sm_p_dist_pos(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		sm_p_dist_pos;
	int		valbrd;
	lst = (*stack);
	sm_p_dist_pos = 0;
	valbrd = INT_MAX;

	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->distance < valbrd && tmp->distance > 0)
		{
			valbrd = tmp->distance;
			sm_p_dist_pos = tmp->position;
		}
		lst = lst->next;
	}
	if(valbrd == INT_MAX)
		return (0);
	return (sm_p_dist_pos);
}

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
	lst = (*b);
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->position = position;
		position++;
		lst = lst->next;
	}
	if((*a) != NULL && (*b) != NULL)
		update_distances(a,b);
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
		return 0;
	return (pos_max);
}

int	calc_b_costs(int ref, t_dlist **b)
{
	int len;
	int position;
	int bcost;
	bcost = 0;
	len = ft_dlstsize((*b));
	position = get_b_effective_pos(ref, b);
	if (position > (len - position) && (position != 0))
		bcost = (len - position) * (-1);
	else
		bcost = position;
	//printf("ref: %i %i %i\n", ref, position, bcost);
	return (bcost);
}

void	calc_phase_one_costs(t_dlist **a, t_dlist **b)
{
	int len;
	t_psu	*tmp;
	t_dlist *lst;

	lst = (*a);
	len = ft_dlstsize(lst);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->position > (len / 2))
			tmp->move_cost_a = 0 - (len - tmp->position);
		else if (tmp->position < (len / 2))
			tmp->move_cost_a = tmp->position;
		else
		{
			if (ft_even(len))
				tmp->move_cost_a = (len / 2);
			else
				tmp->move_cost_a = tmp->position;
		}
		if(b != NULL)
			tmp->move_cost_b = calc_b_costs(tmp->num_data, b);
		tmp->abs_cost = ft_abs(tmp->move_cost_b) + ft_abs(tmp->move_cost_a);
		lst = lst->next;
	}
}

void	perform_pa_rotations(t_dlist **a, t_dlist **b)
{
	update_meta(a, b);
	int sm_p_dist_pos = get_sm_p_dist_pos(a);
	//printf("best pos: %i \n", sm_p_dist_pos);
	while (sm_p_dist_pos != 0)
	{
		ra(a);
		update_meta(a,b);
		sm_p_dist_pos = get_sm_p_dist_pos(a);
	}
}

t_dlist *get_cheapest_node(t_dlist **stack)
{
	t_psu tmp;
	t_dlist *current;
	t_dlist *cheapest;
	int costref;

	cheapest = NULL;
	costref = INT_MAX;
	current = (*stack);
	while (current != NULL)
	{
		tmp = get_content(current->content);

		//if(cheapest == NULL || ((tmp.abs_cost < costref) || (((tmp.abs_cost == costref) &&ft_abs(tmp.distance) < ft_abs(get_content(cheapest->content).distance)))))
		if(cheapest == NULL || (tmp.abs_cost < costref))
		{
		    costref = tmp.abs_cost;
		    cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

void normalize_b(t_dlist **a, t_dlist **b)
{
	int pos_max = get_pos_max(b);
	update_meta(a, b);
	while (pos_max != 0)
	{
		if (pos_max > (ft_dlstsize((*b)) / 2))
			rrb(b);
		else
			rb(b);
		update_meta(a,b);
		pos_max = get_pos_max(b);
	}
}


void	sort_three(t_dlist **a, t_dlist **b)
{
	 int first, second, third;

    update_meta(a, b);
    first = get_content((*a)->content).num_data;
    second = get_content((*a)->next->content).num_data;
    third = get_content((*a)->next->next->content).num_data;

    if (first > second && second < third && first < third) {
        sa(a);  // Swap first two if only the first two are out of order
    } else if (first > second && second > third) {
        sa(a);  // Scenario: 3, 2, 1
        rra(a); // Correct order: 1, 2, 3
    } else if (first > second && second < third && first > third) {
        ra(a);  // Scenario: 3, 1, 2
    } else if (first < second && second > third && first < third) {
        sa(a);  // Scenario: 1, 3, 2
        ra(a);  // Correct order: 1, 2, 3
    } else if (first < second && second > third && first > third) {
        rra(a); // Scenario: 2, 3, 1
    }
}


void	perform_pb_rotations(t_dlist **a, t_dlist **b)
{
	t_dlist *cheapest;
	int		direction;
	int		op_count;

	cheapest = get_cheapest_node(a);
	//printf("CHEAP: %i\n", get_content(cheapest->content).num_data);
	op_count = ft_abs(get_content(cheapest->content).move_cost_a);
	direction = ft_ispos(get_content(cheapest->content).move_cost_a);
	//printf("ROT A: %i\n", op_count);
	//printf("DIR A: %i\n", direction);
	while (op_count > 0)
	{
		if(direction)
			ra(a);
		else
			rra(a);
		op_count--;
	}
	op_count = ft_abs(get_content(cheapest->content).move_cost_b);
	direction = ft_ispos(get_content(cheapest->content).move_cost_b);
	//printf("ROT B: %i\n", op_count);
	//printf("DIR B: %i\n", direction);
	while (op_count > 0)
	{
		if(direction)
			rb(b);
		else
			rrb(b);
		op_count--;
	}
}

void	shift_bottom_up(t_dlist **a, t_dlist **b)
{
	int count;

	update_meta(a,b);
	if(get_pos_max(a) < (ft_dlstsize((*a) - 1) / 2))
	{
		count = get_pos_max(a);
		while(count > 0)
		{
			ra(a);
			update_meta(a,b);
			ft_dlstput(a, put_short, ' ');
			write(1,"\n",1);
			count--;
		}
	}
	else
	{
		count = ((ft_dlstsize((*a)) - 1) - get_pos_max(a));
		while(count > 0)
		{
			rra(a);
			update_meta(a,b);
			ft_dlstput(a, put_short, ' ');
			write(1,"\n",1);
			count--;
		}
	}
}

int	sort(t_dlist **a, t_dlist **b)
{
	int operations;

	operations = 0;

	if(!is_sorted(a, b) && ft_dlstsize((*a)) == 2)
	{
		update_meta(a, b);
		if(get_content((*a)->content).num_data > get_content((*a)->next->content).num_data)
			sa(a);
	} else if(!is_sorted(a, b) && ft_dlstsize((*a)) == 3)
	{
		sort_three(a, b);
	}
	else if (!is_sorted(a, b))
	{
		while(ft_dlstsize((*a)) > 3 && ft_dlstsize((*b)) < 2)
			pb(a, b);
		while(ft_dlstsize((*a)) > 3)
		{
			update_meta(a, b);
			calc_phase_one_costs(a, b);
			perform_pb_rotations(a, b);
			pb(a, b);
		}
		write(1, "\n_______PUSHB_______\n", 21);
		ft_dlstput(a, put_short, ' ');
		write(1, "\n#\n", 3);
		ft_dlstput(b, put_short, ' ');
		write(1, "\n___________________\n", 21);
		sort_three(a, b);
		normalize_b(a, b);
		write(1, "\n_______SORTA_______\n", 21);
		ft_dlstput(a, put_short, ' ');
		write(1, "\n#\n", 3);
		ft_dlstput(b, put_short, ' ');
		write(1, "\n___________________\n", 21);
		//if (ft_dlstsize((*b)) != 0)
		while(ft_dlstsize((*b)) != 0)
		{
			update_meta(a, b);
			ft_dlstput(a, put_content, '\n');
			write(1, "\n#\n", 3);
			ft_dlstput(b, put_content, '\n');
			write(1, "\n___________________\n", 21);
			perform_pa_rotations(a, b);
		//write(1, "\n", 1);
		//ft_dlstput(a, put_short, ' ');
		//write(1, "\n#\n", 3);
		//ft_dlstput(b, put_short, ' ');
		//write(1, "\n",1);
		//	//perform_pa_rotations(a, b);
			pa(a, b);
		}
		//write(1, "\n_______PUSHA_______\n", 21);
		//ft_dlstput(a, put_short, ' ');
		//write(1, "\n#\n", 3);
		//ft_dlstput(b, put_short, ' ');
		//write(1, "\n___________________\n", 21);
		if(!is_sorted(a, b))
		{
			update_meta(a,b);
			ft_dlstput(a, put_short, ' ');
			printf("\na max  %i\n", get_pos_max(a));
			printf("a size %i\n", ft_dlstsize((*a)));
			shift_bottom_up(a, b);
		}
	}
	return (operations);
}

int validate_arg(char *arg)
{
	int i;

	i = 0;
	if (*arg == 43 || *arg == 45)
	{
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
	write(1, "\n_______END_________\n", 21);
	ft_dlstput(stack_a, put_short, ' ');
	write(1, "\n#\n", 3);
	ft_dlstput(stack_b, put_short, ' ');
	write(1, "\n___________________\n", 21);
	write(1, "\n", 1);
	return (0);
}
