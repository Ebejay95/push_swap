/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/14 21:12:10 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_dlist **stack_a;
	t_dlist **stack_b;
	t_dlist *stackanuller;
	t_dlist *stackbnuller;
	
	stackanuller = NULL;
	stackbnuller = NULL;
	stack_a = &stackanuller;
	stack_b = &stackbnuller;
	ft_dlstadd_back(stack_a, ft_dlstnew(content(0)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(1)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(2)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(3)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(4)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(5)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(6)));
	ft_dlstadd_back(stack_b, ft_dlstnew(content(7)));
	ft_dlstadd_back(stack_b, ft_dlstnew(content(8)));
	ft_dlstadd_back(stack_b, ft_dlstnew(content(9)));
	ft_dlstadd_back(stack_b, ft_dlstnew(content(10)));
	ft_dlstadd_back(stack_b, ft_dlstnew(content(11)));
	ft_dlstadd_back(stack_b, ft_dlstnew(content(12)));
	ft_dlstadd_back(stack_b, ft_dlstnew(content(13)));
	ft_putdlst(stack_a, put_content);
	write(1, "#\n", 2);
	ft_putdlst(stack_b, put_content);
	write(1, "___________________\n", 20);
	return (0);
}