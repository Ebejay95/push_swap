/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:23:03 by jeberle           #+#    #+#             */
/*   Updated: 2024/04/27 23:24:02 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_string_input(t_dlist **stack_a, char *str, int *e)
{
	size_t	i;
	int		nodeval;
	size_t	count;
	char	**words;

	i = 0;
	words = NULL;
	count = ft_count_words(str, ' ');
	words = ft_split(str, ' ');
	while (i < count && *e == 0)
	{
		nodeval = ft_atoi(words[i], e);
		if (ft_strcontains(words[i], ' '))
		{
			*e = 1;
			break ;
		}
		if (*e == 0)
			ft_dlstadd_back(stack_a, ft_dlstnew(set_content(nodeval)));
		i++;
	}
}

void	fill_initial(t_dlist **stack_a, int argc, char **argv, int *e)
{
	int		i;
	int		nodeval;

	i = 1;
	if (argc == 2)
		handle_string_input(stack_a, argv[1], e);
	else
	{
		while (i < argc && *e == 0)
		{
			nodeval = ft_atoi(argv[i], e);
			if (ft_strcontains(argv[i], ' '))
			{
				*e = 1;
				break ;
			}
			if (*e == 0)
				ft_dlstadd_back(stack_a, ft_dlstnew(set_content(nodeval)));
			i++;
		}
	}
}
