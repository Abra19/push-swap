/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 02:00:03 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		found_corresp_command(t_stack_m *stack)
{
	int		command[4];
	int		min;
	int		index_c;
	int		i;

	i = 1;
	index_c = 0;
	command[0] = max_two_int(stack->ra, stack->rb);
	command[1] = stack->ra + stack->rrb;
	command[2] = stack->rra + stack->rb;
	command[3] = max_two_int(stack->rra, stack->rrb);
	min = command[0];
	while (i < 4)
	{
		if (command[i] < min)
		{
			min = command[i];
			index_c = i;
		}
		i++;
	}
	return (index_c);
}

void	move_from_b_to_a(t_stack_m *stack)
{
	int		index_c;

	stack->stack_a.head = stack->stack_a.arr[min_int_array(stack->stack_a.arr, \
	stack->stack_a.subsize + stack->stack_a.subgrow)];
	found_min_elem_b(stack);
	stack->stack_b.min_ind = min_int_array(stack->stack_b.transpos,\
	stack->shift);
	found_command(stack, stack->stack_b.min_ind);
	index_c = found_corresp_command(stack);
	if (index_c == 0)
		rarb_mix_command(stack);
	else if (index_c == 1)
		rarrb_mix_command(stack);
	else if (index_c == 2)
		rrarb_mix_command(stack);
	else
		rrarrb_mix_command(stack);
	stack->stack_a.subgrow++;
}

int		found_head_ind(t_stack_m *stack)
{
	int		i;
	int		head_ind;

	i = 0;
	head_ind = 0;
	stack->stack_a.head = stack->stack_a.arr[min_int_array(stack->stack_a.arr, \
	stack->stack_a.subsize + stack->stack_a.subgrow)];
	while (i < stack->stack_a.size)
	{
		if (stack->stack_a.arr[i] == stack->stack_a.head)
		{
			head_ind = i;
			break ;
		}
		i++;
	}
	return (head_ind);
}

void	form_a(t_stack_m *stack)
{
	int		i;
	int		head_ind;

	i = 0;
	head_ind = found_head_ind(stack);
	if (head_ind <= stack->stack_a.size / 2)
	{
		while (stack->stack_a.arr[0] != stack->stack_a.head)
		{
			ra_comm(stack);
			i++;
		}
	}
	else
	{
		while (stack->stack_a.arr[0] != stack->stack_a.head)
		{
			rra_comm(stack);
			i++;
		}
	}
}
