/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/23 23:28:08 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_rrb(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}rrb:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}

void	print_rrr(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}rrr:{eoc}\n", 1);
	if (num_s != 0)
		print_both_stacks(stack, n, m);
	else
		print_stacks(stack, n, m, 0);
}
