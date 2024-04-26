/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/26 17:05:59 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		valbrd;
	lst = (*stack);
	valbrd = INT_MAX;

	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->num_data < valbrd)
		{
			valbrd = tmp->num_data;
		}
		lst = lst->next;
	}
	return (valbrd);
}

int	get_max(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		valbrd;
	lst = (*stack);
	valbrd = INT_MIN;

	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->num_data > valbrd)
		{
			valbrd = tmp->num_data;
		}
		lst = lst->next;
	}
	return (valbrd);
}

t_dlist *get_max_node(t_dlist **stack)
{
	t_dlist	*current = NULL;
	t_dlist	*maxnode = NULL;
	t_psu	*tmp;
	int max = INT_MIN;

	current = (*stack);
	while (current != NULL)
	{
		tmp = current->content;
		if (tmp->num_data > max)
		{
			max = tmp->num_data;
			maxnode = current;
		}
		current = current->next;
	}
	return (maxnode);
}

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

int	get_indx_min(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		valbrd;
	lst = (*stack);
	valbrd = INT_MAX;

	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->index < valbrd)
		{
			valbrd = tmp->index;
		}
		lst = lst->next;
	}
	return (valbrd);
}

int	get_indx_max(t_dlist **stack)
{
	t_psu	*tmp;
	t_dlist *lst;
	int		valbrd;
	lst = (*stack);
	valbrd = INT_MIN;

	if (stack == NULL || (*stack) == NULL)
		return (-1);
	while (lst != NULL)
	{
		tmp = lst->content;
		if (tmp->index > valbrd)
		{
			valbrd = tmp->index;
		}
		lst = lst->next;
	}
	return (valbrd);
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

int is_revsinglesorted(t_dlist **a)
{
	t_dlist	*current;
	t_psu cur;
	t_psu cmp;

	current = (*a);
	while (current != NULL)
	{
		if(current->prev != NULL)
		{
			cur = get_content(current->content);
			cmp = get_content(current->prev->content);
			if(cur.num_data < cmp.num_data)
				return (0);
		}
		current = current->next; 
	}
	return (1);
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


void	find_target(int n, t_dlist **a)
{
	t_psu	*tmp;

	if ((*a) != NULL)
	{
		while ((*a) != NULL)
		{
			tmp = (*a)->content;
			tmp->distance = ft_abs(n - tmp->index) - 1;
			a = &((*a)->next);
		}
	}
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

void	setindexes(t_dlist **a)
{
	int index = 0;
	t_psu	*tmp;
	t_psu	*smallestitem;
	t_dlist *lst;
	t_dlist *smallest;
	int smallestval = 0;

	while (index < (ft_dlstsize((*a))))
	{
		smallest = NULL;
		smallestval = INT_MAX;
		lst = (*a);
		while (lst != NULL)
		{
			tmp = lst->content;
			if(tmp->index == -1 && tmp->num_data < smallestval)
			{
				smallestval = tmp->num_data;
				smallest = lst;
			}
			lst = lst->next;
		}
		if(smallest != NULL)
		{
			smallestitem = smallest->content;
			smallestitem->index = index;
			index++;
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

void	clear_costs(t_dlist **a, t_dlist **b)
{
	t_psu	*tmp;
	t_dlist *lst;

	lst = (*a);
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->move_cost_a = 0;
		tmp->move_cost_b = 0;
		tmp->distance = 0;
		tmp->abs_cost = 0;
		lst = lst->next;
	}
	lst = (*b);
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->move_cost_a = 0;
		tmp->move_cost_b = 0;
		tmp->distance = 0;
		tmp->abs_cost = 0;
		lst = lst->next;
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
		return 0;
	return (pos_max);
}

int	calc_othertack(int ref, t_dlist **b)
{
	int len;
	int position;
	int cost;
	cost = 0;
	len = ft_dlstsize((*b));
	position = get_b_effective_pos(ref, b);
	if (position > (len - position) && (position != 0))
		cost = (len - position) * (-1);
	else
		cost = position;
	return (cost);
}

//int get_next_possible_ndx(int current_index, t_dlist **a)
//{
//	t_dlist *current = (*a);
//	int target = -1;
//	int a_has_greater = 1;
//	while (current != NULL)
//	{
//		if(current->next != NULL)
//		{
//			if(current_index > get_content(current->next->content).index)
//			{
//				a_has_greater = 0;
//				target = get_content(current->next->content).index;
//			}
//			else if (a_has_greater == 0 && current_index < get_content(current->next->content).index)
//			{
//				target = get_content(current->next->content).index;
//			}
//		}
//		current = current->next;
//	}
//	if(current_index > get_indx_max(a))
//		target = get_indx_min(a);
//	if(target == -1)
//		target = get_indx_min(a);
//	return (target);
//}

int get_next_possible_ndx(int current_index, t_dlist **a)
{
	t_dlist *current = (*a);
	int	next_greater = 0;
	int	smalles_next_greater = INT_MAX;
	int target = -1;
	int a_has_greater = 1;
	while (current != NULL)
	{
		if(current->next != NULL)
		{
			if(current_index > get_content(current->next->content).index)
			{
				a_has_greater = 0;
				target = get_content(current->next->content).index;
			}
			else if (a_has_greater == 0 && current_index < get_content(current->next->content).index)
			{
				target = get_content(current->next->content).index;
			}
		}
		current = current->next;
	}
	if(current_index > get_indx_max(a))
		target = get_indx_min(a);
	if(target == -1)
		target = get_indx_min(a);
	return (target);
}

int	 getposbydex(int index, t_dlist **a)
{
	t_dlist	*current;
	t_psu *tmp;

	current = (*a);
	while (current != NULL)
	{
		tmp = current->content;
		if (index == tmp->index)
			return (get_content(current->content).position);
		current = current->next; 
	}
	return (get_content((*a)->content).position);
}

void	calculate_costs(t_dlist **a, t_dlist **b)
{
	int len;
	t_psu	ref = get_content((*a)->content);
	t_psu	*tmp;
	t_dlist *lst;

	lst = (*b);
	len = ft_dlstsize(lst);
	while (lst != NULL)
	{
		tmp = lst->content;
		tmp->distance = ft_abs(ref.index - tmp->index);
		if (tmp->position > (len / 2))
			tmp->move_cost_b = 0 - (len - tmp->position);
		else if (tmp->position < (len / 2))
			tmp->move_cost_b = tmp->position;
		else
		{
			if (ft_even(len))
				tmp->move_cost_b = (len / 2);
			else
				tmp->move_cost_b = tmp->position;
		}

		ft_printf("fuer i %i: ", get_content(lst->content).index);
		int	target_distance = get_next_possible_ndx(get_content(lst->content).index, a);
		int	targetpos = getposbydex(target_distance, a);
		ft_printf("beste i -> %i %i\n", target_distance, targetpos);
			//ft_printf("aposreq %i \n", ref.index);
		tmp->move_cost_a = targetpos;
		tmp->abs_cost = ft_abs(tmp->move_cost_a) + ft_abs(tmp->move_cost_b);
		lst = lst->next;
	}
}

//void	calculate_costs(t_dlist **a, t_dlist **b)
//{
//	int	alen = ft_dlstsize((*a));
//	int	blen = ft_dlstsize((*b));
//	t_dlist *current = (*b);
//
//	while(current != NULL)
//	{
//		t_psu *bcontent = current->content;
//
//		current = current->next;
//	}
//}

//void	calculate_costs(t_dlist **a, t_dlist **b)
//{
//	int len;
//	t_psu	*tmp;
//	t_dlist *lst;
//
//	lst = (*b);
//	len = ft_dlstsize(lst);
//	while (lst != NULL)
//	{
//		tmp = lst->content;
//		if (tmp->position > (len / 2))
//			tmp->move_cost_b = 0 - (len - tmp->position);
//		else if (tmp->position < (len / 2))
//			tmp->move_cost_b = tmp->position;
//		else
//		{
//			if (ft_even(len))
//				tmp->move_cost_b = (len / 2);
//			else
//				tmp->move_cost_b = tmp->position;
//		}
//		if(b != NULL)
//			tmp->move_cost_a = calc_othertack(tmp->num_data, a);
//		tmp->abs_cost = ft_abs(tmp->move_cost_a) + ft_abs(tmp->move_cost_b);
//		lst = lst->next;
//	}
//}

int	can_insert(t_dlist **a, t_psu *b_content)
{
	t_dlist *current_a = (*a);
	int data = b_content->num_data;

	if(!current_a || data <= get_content(current_a->content).num_data)
		return (1);
	while(current_a->next != NULL)
	{
		int current_data = get_content(current_a->content).num_data;
		int next_data = get_content(current_a->next->content).num_data;
		if(current_data <= data && data <= next_data)
			return (1);
		current_a = current_a->next;
	}
	if(data >= get_content(current_a->content).num_data)
		return (1);
	return (0);
}

t_dlist *get_cheapest_node(t_dlist **a, t_dlist **b)
{
	t_psu tmp;
	t_dlist *current;
	t_dlist *cheapest;
	int costref;

	cheapest = NULL;
	costref = INT_MAX;
	current = (*b);
	while (current != NULL)
	{
		tmp = get_content(current->content);
		if(can_insert(a,&tmp))
		{
			int cost = tmp.abs_cost;
			if (cost < costref)
			{
		    	costref = cost;
		    	cheapest = current;
			}
		}
		current = current->next;
	}
	return (cheapest);
}

void shift_bottom_down(t_dlist **a, t_dlist **b, int *operations)
{
	int pos_max = get_pos_max(b);
	update_meta(a, b);
	while (pos_max != 0)
	{
		if (pos_max > (ft_dlstsize((*b)) / 2))
			*operations = *operations + rrb(b);
		else
			*operations = *operations + rb(b);
		update_meta(a,b);
		pos_max = get_pos_max(b);
	}
}


void	sort_three(t_dlist **a)
{
	t_dlist	*maxnode;

	maxnode = get_max_node(a);
	if(maxnode == (*a))
		ra(a);
	else if(maxnode == (*a)->next)
		rra(a);
	if(get_content((*a)->content).num_data > get_content((*a)->next->content).num_data)
		sa(a);
}


void	perform_pb_rotations(t_dlist **a, t_dlist **b)
{
	t_dlist *cheapest;
	int		adirection;
	int		aop_count;
	int		bdirection;
	int		bop_count;
	int		minopcount;

	cheapest = get_cheapest_node(a, b);
	printf("cheapest %i (%i %i)\n", get_content(cheapest->content).num_data, get_content(cheapest->content).move_cost_a, get_content(cheapest->content).move_cost_b);
	aop_count = ft_abs(get_content(cheapest->content).move_cost_a);
	adirection = ft_ispos(get_content(cheapest->content).move_cost_a);
	bop_count = ft_abs(get_content(cheapest->content).move_cost_b);
	bdirection = ft_ispos(get_content(cheapest->content).move_cost_b);
	printf("perform_pb_rotations %i %i \n", aop_count, bop_count);
	minopcount = (aop_count < bop_count) ? aop_count : bop_count;

	while (minopcount > 0 && adirection == bdirection)
	{
		if (adirection)
			rr(a, b);
		else
			rrr(a, b);
		minopcount--;
		aop_count--;
		bop_count--;
	}
	while (aop_count > 0)
	{
		if(adirection)
			ra(a);
		else
			rra(a);
		aop_count--;
	}
	while (bop_count > 0)
	{
		if(bdirection)
			rb(b);
		else
			rrb(b);
		bop_count--;
	}
}

void	perform_pa_rotations(t_dlist **a, t_dlist **b, int *operations)
{
	update_meta(a, b);
	int sm_p_dist_pos = get_sm_p_dist_pos(a);
	while (sm_p_dist_pos != 0)
	{
		if (sm_p_dist_pos > (ft_dlstsize((*a)) / 2))
			*operations = *operations + rra(a);
		else
			*operations = *operations + ra(a);
		update_meta(a,b);
		sm_p_dist_pos = get_sm_p_dist_pos(a);
	}
}

//void	perform_pa_rotations(t_dlist **a, t_dlist **b, int *operations)
//{
//	t_dlist *cheapest;
//	int		direction;
//	int		op_count;
//
//	cheapest = get_cheapest_node(a);
//	op_count = ft_abs(get_content(cheapest->content).move_cost_a);
//	direction = ft_ispos(get_content(cheapest->content).move_cost_a);
//	while (op_count > 0)
//	{
//		if(direction)
//			*operations = *operations + ra(a);
//		else
//			*operations = *operations + rra(a);
//		op_count--;
//	}
//	op_count = ft_abs(get_content(cheapest->content).move_cost_b);
//	direction = ft_ispos(get_content(cheapest->content).move_cost_b);
//	while (op_count > 0)
//	{
//		if(direction)
//			*operations = *operations + rb(b);
//		else
//			*operations = *operations + rrb(b);
//		op_count--;
//	}
//}

void	shift_bottom_up(t_dlist **a, t_dlist **b, int *operations)
{
	int count;

	update_meta(a,b);
	if(get_pos_max(a) < (ft_dlstsize((*a) - 1) / 2))
	{
		count = get_pos_max(a);
		while(count > 0)
		{
			*operations = *operations + ra(a);
			update_meta(a,b);
			count--;
		}
	}
	else
	{
		count = ((ft_dlstsize((*a)) - 1) - get_pos_max(a));
		while(count > 0)
		{
			*operations = *operations + rra(a);
			update_meta(a,b);
			count--;
		}
	}
}


int	sort(t_dlist **a, t_dlist **b)
{
	int operations;
	int sep;

	operations = 0;
	sep = (ft_dlstsize((*a)) / 3);
	setindexes(a);
	if(!is_sorted(a, b) && ft_dlstsize((*a)) == 2)
	{
		update_meta(a, b);
		if(get_content((*a)->content).num_data > get_content((*a)->next->content).num_data)
			operations = operations + sa(a);
	}
	else if(!is_sorted(a, b) && ft_dlstsize((*a)) == 3)
	{
		sort_three(a);
	}
	else if(!is_sorted(a, b) && ft_dlstsize((*a)) == 4)
	{
		// max node push push
		sort_three(a);
	}
	else if(!is_sorted(a, b) && ft_dlstsize((*a)) == 5)
	{
		// max node push push
		sort_three(a);
	}
	////// 3 - 5 sollten nicht mehr als 5 operationen brauchen/
	else if (!is_sorted(a, b))
	{
		ft_dlstput(a, put_content, '\n');
		write(1, "\n", 1);
		ft_dlstput(b, put_content, '\n');
		write(1, "\n", 1);
		while (ft_dlstsize((*a)) > 0)
		{
			if(get_content((*a)->content).index < sep)
			{
				pb(a, b);
				sep++;
			}
			else
				ra(a);
		}
		while(ft_dlstsize((*a)) > 3)
		{
			operations = operations + pb(a, b);
		}
		clear_costs(a, b);
		pa(a,b);
		pa(a,b);
		pa(a,b);
		while(ft_dlstsize((*b)) != 0)
		{
			update_meta(a, b);
			calculate_costs(a, b);
			ft_dlstput(a, put_content, '\n');
			write(1, "\n", 1);
			ft_dlstput(b, put_content, '\n');
			write(1, "\n", 1);
			perform_pb_rotations(a, b);
			pa(a,b);
			ft_dlstput(a, put_short, ' ');
			write(1, "\n", 1);
			ft_dlstput(b, put_short, ' ');
			write(1, "\n", 1);
			
			// update_meta(a, b);
			// calculate_costs(a, b);
			// ft_dlstput(a, put_content, '\n');
			// write(1, "\n", 1);
			// ft_dlstput(b, put_content, '\n');
			// write(1, "\n", 1);
			// perform_pb_rotations(a, b);
			// pa(a,b);
			// ft_dlstput(a, put_short, ' ');
			// write(1, "\n", 1);
			// ft_dlstput(b, put_short, ' ');
			// write(1, "\n", 1);
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

void	handle_string_input(t_dlist **stack_a, char *str, int *e)
{
	size_t i = 0;
	size_t	count = ft_count_words(str, ' ');
	char	**words = ft_split(str, ' ');
	while (i < count)
	{
		if(validate_arg(words[i]) != 0)
			(*e)++;
		ft_dlstadd_back(stack_a, ft_dlstnew(set_content(ft_atoi(words[i]))));
		i++;
	}
}

void	fill_initial(t_dlist **stack_a, int argc, char **argv, int *e)
{
	int		i;

	i = 1;
	if (argc == 2)
		handle_string_input(stack_a, argv[1], e);
	else
	{
		while (i < argc)
		{
			if(validate_arg(argv[i]) != 0)
				(*e)++;
			ft_dlstadd_back(stack_a, ft_dlstnew(set_content(ft_atoi(argv[i]))));
			i++;
		}
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
	sort(stack_a, stack_b);
	write(1, "\n", 1);
	ft_dlstput(stack_a, put_short, ' ');
	ft_dlstput(stack_b, put_short, ' ');
	write(1, "\n", 1);
	return (0);
}
