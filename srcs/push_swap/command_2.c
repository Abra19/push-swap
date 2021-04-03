/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/18 21:28:14 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	if (stack->shift > 1)
	{
		i = 0;
		tmp = stack->stack_b.arr[0];
		while (i < stack->shift - 1)
		{
			stack->stack_b.arr[i] = stack->stack_b.arr[i + 1];
			i++;
		}
		stack->stack_b.arr[i] = tmp;
	}
}

void	rr_command(t_stack_m *stack)
{
	ra_command(stack);
	rb_command(stack);
}

void	rra_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	if (stack->stack_a.size - stack->shift > 1)
	{
		i = stack->stack_a.size - stack->shift - 1;
		tmp = stack->stack_a.arr[i];
		while (i > 0)
		{
			stack->stack_a.arr[i] = stack->stack_a.arr[i - 1];
			i--;
		}
		stack->stack_a.arr[i] = tmp;
	}
}

void	rrb_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	if (stack->shift > 1)
	{
		i = stack->shift - 1;
		tmp = stack->stack_b.arr[i];
		while (i > 0)
		{
			stack->stack_b.arr[i] = stack->stack_b.arr[i - 1];
			i--;
		}
		stack->stack_b.arr[i] = tmp;
	}
}

void	rrr_command(t_stack_m *stack)
{
	rra_command(stack);
	rrb_command(stack);
}
