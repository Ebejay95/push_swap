/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:23:03 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/02 17:21:22 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_string_input(t_dlist **a, char *str, int *e)
{
	size_t	i;
	int		nodeval;
	size_t	count;
	char	**w;
	t_dlist	*tmp;

	i = 0;
	w = NULL;
	count = ft_count_words(str, ' ');
	w = ft_split(str, ' ');
	while (i < count && *e == 0)
	{
		nodeval = ft_atoi(w[i], e);
		tmp = ft_dlstnew(set_content(nodeval));
		if (ft_strcontains(w[i], ' ') || ft_dlstfind(a, tmp->content, cmp_c))
		{
			ft_dlstclear(&tmp, del_content);
			*e = 1;
			break ;
		}
		ft_dlstadd_back(a, tmp);
		i++;
	}
}

void	fill_initial(t_dlist **a, int argc, char **argv, int *e)
{
	int		i;
	int		nodeval;
	t_dlist	*tmp;

	i = 0;
	if (argc == 2)
	{
		handle_string_input(a, argv[1], e);
		i++;
	}
	else
		i = 1;
	while (i < argc && *e == 0 && i != 0)
	{
		nodeval = ft_atoi(argv[i], e);
		tmp = ft_dlstnew(set_content(nodeval));
		if (ft_strcontains(argv[i], ' ') || ft_dlstfind(a, tmp->content, cmp_c))
		{
			ft_dlstclear(&tmp, del_content);
			*e = 1;
			break ;
		}
		ft_dlstadd_back(a, tmp);
		i++;
	}
}

void	free_stacks(t_dlist **a, t_dlist **b)
{
	if (a != NULL)
	{
		ft_dlstclear(a, del_content);
		a = NULL;
	}
	if (b != NULL)
	{
		ft_dlstclear(b, del_content);
		b = NULL;
	}
}
