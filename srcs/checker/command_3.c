/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/23 19:30:14 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		rr_one_element(t_stack_m *stack, int *j)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = stack->stack_a.arr[0];
	while (i < stack->stack_a.size - stack->shift - 1)
	{
		stack->stack_a.arr[i] = stack->stack_a.arr[i + 1];
		i++;
	}
	*j = i;
	stack->stack_a.arr[i] = tmp;
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
	return (i);
}

void	rr_command(t_stack_m *stack)
{
	int		i;
	int		j;

	stack->num_comm++;
	if (stack->stack_a.size - stack->shift > 1)
	{
		i = rr_one_element(stack, &j);
		if (stack->debag == 1)
			print_rr(stack, i, j, 1);
	}
	else
	{
		if (stack->debag == 1)
			print_rr(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	rrb_command(t_stack_m *stack)
{
	int		i;
	int		tmp;

	stack->num_comm++;
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
		if (stack->debag == 1)
			print_rrb(stack, 0, stack->shift - 1, 2);
	}
	else
	{
		if (stack->debag == 1)
			print_rrb(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	rrr_one_element(t_stack_m *stack)
{
	int		i;
	int		tmp;

	i = stack->stack_a.size - stack->shift - 1;
	tmp = stack->stack_a.arr[i];
	while (i > 0)
	{
		stack->stack_a.arr[i] = stack->stack_a.arr[i - 1];
		i--;
	}
	stack->stack_a.arr[i] = tmp;
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
	stack->num_comm++;
	if (stack->stack_a.size - stack->shift > 1)
	{
		rrr_one_element(stack);
		if (stack->debag == 1)
			print_rrr(stack, stack->shift - 1,\
			stack->stack_a.size - stack->shift - 1, 1);
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
