/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/24 16:48:45 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	count_width_stack(t_stack_m *stack, int i)
{
	stack->size1 = ft_intlen(stack->stack_a.arr[i], 10);
	stack->size2 = ft_intlen(stack->stack_b.arr[i], 10);
	if (stack->stack_a.arr[i] < 0)
		stack->size1++;
	if (stack->stack_b.arr[i] < 0)
		stack->size2++;
	ft_printf("%w{yellow}|{eoc}", 1);
}

void	print_space(int size)
{
	int		j;

	j = 0;
	while (j < INTSIZE - size)
	{
		ft_printf("%w ", 1);
		j++;
	}
}

void	add_color(int color, int *arr, int i)
{
	if (color == 1)
		ft_printf("%w{red}%d{eoc}", 1, arr[i]);
	else
		ft_printf("%w%d", 1, arr[i]);
}

void	print_stack_a(t_stack_m *stack, int i, int k)
{
	count_width_stack(stack, i);
	if (k < stack->stack_a.size - stack->shift)
	{
		print_space(stack->size1);
		if ((i == stack->n || i == stack->l) && stack->num_s == 1 &&\
		stack->n < stack->stack_a.size)
			add_color(stack->color, stack->stack_a.arr, i);
		else
			ft_printf("%w%d", 1, stack->stack_a.arr[i]);
	}
	else
		print_space(0);
}
