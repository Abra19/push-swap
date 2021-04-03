/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:58:45 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_bottom(t_stack_m *stack)
{
	int		i;

	i = 1;
	while (i < stack->stack_a.size - stack->shift)
	{
		if (stack->stack_a.arr[i] == stack->stack_a.head)
			break ;
		i++;
	}
	return (i);
}

int		less_then_head(t_stack_m *stack)
{
	int		i;

	i = 1;
	if (stack->stack_a.head == stack->stack_a.arr[0])
		return (0);
	else if (stack->stack_a.head ==\
		stack->stack_a.arr[stack->stack_a.size - stack->shift - 1])
		return (stack->stack_a.size - stack->shift - 1);
	else
	{
		while (i < stack->stack_a.size - stack->shift)
		{
			if (stack->stack_a.arr[i] == stack->stack_a.head)
				break ;
			i++;
		}
		return (i);
	}
}

int		head_in_top(t_stack_m *stack, int j)
{
	int		i;

	i = 1;
	if (stack->stack_b.arr[j] >\
	stack->stack_a.arr[stack->stack_a.size - stack->shift - 1])
		return (0);
	else
	{
		while (i < stack->stack_a.size - stack->shift)
		{
			if (stack->stack_b.arr[j] > stack->stack_a.arr[i - 1] && \
			stack->stack_b.arr[j] < stack->stack_a.arr[i])
				break ;
			i++;
		}
		return (i);
	}
}

int		head_in_bottom(t_stack_m *stack, int j)
{
	int		i;

	i = 1;
	if (stack->stack_a.arr[0] > stack->stack_b.arr[j])
		return (0);
	else
	{
		while (i < stack->stack_a.size - stack->shift)
		{
			if ((stack->stack_b.arr[j] > stack->stack_a.arr[i - 1] && \
			stack->stack_b.arr[j] < stack->stack_a.arr[i]) ||\
			(stack->stack_b.arr[j] > stack->stack_a.arr[i - 1] &&\
			stack->stack_a.arr[i] == stack->stack_a.head))
				break ;
			i++;
		}
		return (i);
	}
}
