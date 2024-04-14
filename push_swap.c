/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:21:20 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/04/14 12:01:11 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_dlist **stack_a;
	t_dlist *stacknuller;
	
	stacknuller = NULL;
	stack_a = &stacknuller;
	ft_dlstadd_back(stack_a, ft_dlstnew(content(42)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(15)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(-35)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(622)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(0)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(9356)));
	ft_dlstadd_back(stack_a, ft_dlstnew(content(-234524)));
	ft_putdlst(stack_a, put_content);
	return (0);
}