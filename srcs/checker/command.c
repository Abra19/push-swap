/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/23 17:03:48 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_command(t_stack_m *stack)
{
	stack->num_comm++;
	if (stack->stack_a.size - stack->shift > 1)
	{
		ft_swap_int(&stack->stack_a.arr[0], &stack->stack_a.arr[1]);
		if (stack->debag == 1)
			print_sa(stack, 0, 1, 1);
	}
	else
	{
		if (stack->debag == 1)
			print_sa(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	sb_command(t_stack_m *stack)
{
	stack->num_comm++;
	if (stack->shift > 1)
	{
		ft_swap_int(&stack->stack_b.arr[0], &stack->stack_b.arr[1]);
		if (stack->debag == 1)
			print_sb(stack, 0, 1, 2);
	}
	else
	{
		if (stack->debag == 1)
			print_sb(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	ss_command(t_stack_m *stack)
{
	stack->num_comm++;
	if (stack->stack_a.size - stack->shift > 1)
	{
		ft_swap_int(&stack->stack_a.arr[0], &stack->stack_a.arr[1]);
		if (stack->shift > 1)
			ft_swap_int(&stack->stack_b.arr[0], &stack->stack_b.arr[1]);
		if (stack->debag == 1)
			print_ss(stack, 0, 1, 1);
	}
	else
	{
		if (stack->debag == 1)
			print_ss(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}

void	pb_one_elem(t_stack_m *stack)
{
	int		i;

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

void	pb_command(t_stack_m *stack)
{
	stack->num_comm++;
	if (stack->stack_a.size - stack->shift > 0)
	{
		stack->shift++;
		pb_one_elem(stack);
		if (stack->debag == 1)
			print_pb(stack, stack->stack_a.size, 0, 2);
	}
	else
	{
		if (stack->debag == 1)
			print_pb(stack, 0, 0, 0);
	}
	if (stack->draw == 1 && stack->stack_a.size <\
	min_two_int(WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD))
		visualize_sort(stack);
}
