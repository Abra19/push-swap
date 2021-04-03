/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:16:57 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa_one_elem(t_stack_m *stack)
{
	int		i;

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

void	pa_command(t_stack_m *stack)
{
	stack->num_comm++;
	if (stack->shift > 0)
	{
		stack->shift--;
		pa_one_elem(stack);
		if (stack->debag == 1)
			print_pa(stack, 0, stack->stack_a.size, 1);
	}
	else
	{
		if (stack->debag == 1)
			print_pa(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	ra_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	stack->num_comm++;
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
		if (stack->debag == 1)
			print_ra(stack, 0, i, 1);
	}
	else
	{
		if (stack->debag == 1)
			print_ra(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	rb_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	stack->num_comm++;
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
		if (stack->debag == 1)
			print_rb(stack, 0, i, 2);
	}
	else
	{
		if (stack->debag == 1)
			print_rb(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	rra_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	stack->num_comm++;
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
		if (stack->debag == 1)
			print_rra(stack, 0, stack->stack_a.size - stack->shift - 1, 1);
	}
	else
	{
		if (stack->debag == 1)
			print_rra(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}
