/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:57:27 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		greather_head(t_stack_m *stack, int j)
{
	int		i;

	i = 1;
	if (stack->stack_b.arr[j] < stack->stack_a.arr[0] &&\
	stack->stack_b.arr[j] >\
	stack->stack_a.arr[stack->stack_a.size - stack->shift - 1])
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

int		found_place_a(t_stack_m *stack, int j)
{
	int		i;

	if (stack->stack_b.arr[j] == stack->stack_a.bottom)
		i = stack_bottom(stack);
	else if (stack->stack_b.arr[j] < stack->stack_a.head)
		i = less_then_head(stack);
	else
	{
		if (stack->stack_a.head == stack->stack_a.arr[0])
			i = head_in_top(stack, j);
		else if (stack->stack_a.head ==\
		stack->stack_a.arr[stack->stack_a.size - stack->shift - 1])
			i = head_in_bottom(stack, j);
		else
			i = greather_head(stack, j);
	}
	return (i);
}

void	found_command(t_stack_m *stack, int j)
{
	int		i;

	i = found_place_a(stack, j);
	stack->spec_mode = 0;
	stack->ra = i;
	stack->rra = stack->stack_a.size - stack->shift - i;
	stack->rb = j;
	stack->rrb = stack->shift - j;
}

void	found_min_elem_b(t_stack_m *stack)
{
	int		j;

	j = 0;
	while (j < stack->shift)
	{
		found_command(stack, j);
		stack->stack_b.transpos[j] =\
		min_four_int(max_two_int(stack->ra, stack->rb),\
		max_two_int(stack->rra, stack->rrb), stack->ra + stack->rrb,\
		stack->rra + stack->rb);
		j++;
	}
}

void	ra_gt_rb(t_stack_m *stack)
{
	int		i;

	i = 1;
	while (i <= stack->rb)
	{
		rr_comm(stack);
		i++;
	}
	i = 1;
	while (i <= stack->ra - stack->rb)
	{
		ra_comm(stack);
		i++;
	}
}
