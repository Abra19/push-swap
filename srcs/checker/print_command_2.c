/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/23 23:28:08 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_pa(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}pa:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}

void	print_ra(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}ra:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}

void	print_rb(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}rb:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}

void	print_rr(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}rr:{eoc}\n", 1);
	if (num_s != 0)
		print_both_stacks(stack, n, m);
	else
		print_stacks(stack, n, m, 0);
}

void	print_rra(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}rra:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}
