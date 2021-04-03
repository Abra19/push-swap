/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:44:23 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_command(t_stack_m *stack)
{
	if (stack->stack_a.size - stack->shift > 1)
		ft_swap_int(&stack->stack_a.arr[0], &stack->stack_a.arr[1]);
}

void	sb_command(t_stack_m *stack)
{
	if (stack->shift > 1)
		ft_swap_int(&stack->stack_b.arr[0], &stack->stack_b.arr[1]);
}

void	pb_command(t_stack_m *stack)
{
	int		i;

	if (stack->stack_a.size - stack->shift > 0)
	{
		stack->shift++;
		i = stack->stack_b.size - 1;
		while (i > 0)
		{
			stack->stack_b.arr[i] = stack->stack_b.arr[i - 1];
			i--;
		}
		stack->stack_b.arr[0] = stack->stack_a.arr[0];
		while (i < stack->stack_a.size - 1)
		{
			stack->stack_a.arr[i] = stack->stack_a.arr[i + 1];
			i++;
		}
		stack->stack_a.arr[i] = 0;
	}
}

void	pa_command(t_stack_m *stack)
{
	int		i;

	if (stack->shift > 0)
	{
		stack->shift--;
		i = stack->stack_a.size - 1;
		while (i > 0)
		{
			stack->stack_a.arr[i] = stack->stack_a.arr[i - 1];
			i--;
		}
		stack->stack_a.arr[0] = stack->stack_b.arr[0];
		while (i < stack->stack_b.size - 1)
		{
			stack->stack_b.arr[i] = stack->stack_b.arr[i + 1];
			i++;
		}
		stack->stack_b.arr[i] = 0;
	}
}

void	ra_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	if (stack->stack_a.size - stack->shift > 1)
	{
		i = 0;
		tmp = stack->stack_a.arr[0];
		while (i < stack->stack_a.size - stack->shift - 1)
		{
			stack->stack_a.arr[i] = stack->stack_a.arr[i + 1];
			i++;
		}
		stack->stack_a.arr[i] = tmp;
	}
}
