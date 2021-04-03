/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:34:48 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack_b(t_stack_m *stack, int i, int m)
{
	if (m > 0)
	{
		print_space(stack->size2);
		if ((i == stack->n || i == stack->l) && stack->num_s == 2 &&\
		stack->l < stack->stack_a.size)
			add_color(stack->color, stack->stack_b.arr, i);
		else
			ft_printf("%w%d", 1, stack->stack_b.arr[i]);
	}
	else
		print_space(0);
}

void	print_stacks(t_stack_m *stack, int n, int l, int num_s)
{
	int		i;
	int		k;
	int		m;

	i = 0;
	k = 0;
	m = init_print(stack, n, l, num_s);
	while (i < stack->stack_a.size)
	{
		print_stack_a(stack, i, k);
		k++;
		ft_printf("%w{yellow}|{eoc}", 1);
		print_stack_b(stack, i, m);
		m--;
		ft_printf("%w{yellow}|{eoc}\n", 1);
		i++;
	}
	ft_printf("%w{yellow}|-----{green}A{yellow}-----|-"
	"----{green}B{yellow}-----|{eoc}\n", 1);
}

void	print_a_in_both(t_stack_m *stack, int i, int k)
{
	count_width_stack(stack, i);
	if (k < stack->stack_a.size - stack->shift)
	{
		print_space(stack->size1);
		if ((i == 0 || i == stack->l) && 0 < stack->stack_a.size)
			add_color(stack->color, stack->stack_a.arr, i);
		else
			ft_printf("%w%d", 1, stack->stack_a.arr[i]);
	}
	else
		print_space(0);
}

void	print_b_in_both(t_stack_m *stack, int i, int m)
{
	if (m > 0)
	{
		print_space(stack->size2);
		if ((i == 0 || i == stack->n) && stack->n < stack->stack_a.size)
			add_color(stack->color, stack->stack_b.arr, i);
		else
			ft_printf("%w%d", 1, stack->stack_b.arr[i]);
	}
	else
		print_space(0);
}

void	print_both_stacks(t_stack_m *stack, int n, int l)
{
	int		i;
	int		k;
	int		m;

	i = 0;
	k = 0;
	m = init_print_both(stack, n, l);
	while (i < stack->stack_a.size)
	{
		print_a_in_both(stack, i, k);
		k++;
		ft_printf("%w{yellow}|{eoc}", 1);
		print_b_in_both(stack, i, m);
		m--;
		ft_printf("%w{yellow}|{eoc}\n", 1);
		i++;
	}
	ft_printf("%w{yellow}|-----{green}A{yellow}-----|"
	"-----{green}B{yellow}-----|{eoc}\n", 1);
}
