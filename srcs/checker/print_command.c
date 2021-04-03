/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/23 23:25:50 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_start(t_stack_m *stack, int n, int m, int num_s)
{
	if (stack->debag == 1)
	{
		ft_printf("%w{blue}start:{eoc}\n", 1);
		print_stacks(stack, n, m, num_s);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	print_sa(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}sa:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}

void	print_sb(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}sb:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}

void	print_ss(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}ss:{eoc}\n", 1);
	if (num_s != 0)
		print_both_stacks(stack, m, m);
	else
		print_stacks(stack, n, m, 0);
}

void	print_pb(t_stack_m *stack, int n, int m, int num_s)
{
	ft_printf("%w{blue}pb:{eoc}\n", 1);
	print_stacks(stack, n, m, num_s);
}
