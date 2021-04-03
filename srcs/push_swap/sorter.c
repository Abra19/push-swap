/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/20 21:49:47 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort(t_stack_m *stack)
{
	if (stack->stack_a.size == 2)
		sa_comm(stack);
	else if (stack->stack_a.size == 3)
		sort_int_3(stack);
	else if (stack->stack_a.size == 4)
		sort_int_4(stack);
	else if (stack->stack_a.size == 5)
		sort_int_5(stack);
}

int		sorter(t_stack_m *stack)
{
	if (stack->stack_a.size >= 2 && stack->stack_a.size <= 5)
		hard_sort(stack);
	else
	{
		if ((stack->stack_a.subsize =\
		max_lenght_arr(stack, stack->stack_a.size)) == 0)
			return (0);
		make_max_length_arr(stack);
		if ((stack->stack_b.transpos = (int *)ft_memalloc(sizeof(int) *\
		stack->shift)) == 0)
			return (0);
		ft_bzero((void *)stack->stack_b.transpos, stack->shift);
		while (stack->shift != 0)
			move_from_b_to_a(stack);
		form_a(stack);
	}
	return (1);
}

void	sort_int_3(t_stack_m *stack)
{
	if (stack->stack_a.arr[0] < stack->stack_a.arr[1] &&\
	stack->stack_a.arr[0] < stack->stack_a.arr[2] &&\
	stack->stack_a.arr[1] > stack->stack_a.arr[2])
		sara_comm(stack);
	else if (stack->stack_a.arr[0] > stack->stack_a.arr[1] &&\
	stack->stack_a.arr[0] < stack->stack_a.arr[2] &&\
	stack->stack_a.arr[1] < stack->stack_a.arr[2])
		sa_comm(stack);
	else if (stack->stack_a.arr[0] < stack->stack_a.arr[1] &&\
	stack->stack_a.arr[0] > stack->stack_a.arr[2] &&\
	stack->stack_a.arr[1] > stack->stack_a.arr[2])
		rra_comm(stack);
	else if (stack->stack_a.arr[0] > stack->stack_a.arr[1] &&\
		stack->stack_a.arr[1] > stack->stack_a.arr[2])
		sarra_comm(stack);
	else if (stack->stack_a.arr[0] > stack->stack_a.arr[1] &&\
		stack->stack_a.arr[0] > stack->stack_a.arr[2] &&\
		stack->stack_a.arr[1] < stack->stack_a.arr[2])
		ra_comm(stack);
}

void	common_for_4(t_stack_m *stack)
{
	stack->num_comm++;
	pb_command(stack);
	ft_printf("%wpb\n", stack->fd);
	sort_int_3(stack);
	stack->num_comm++;
	pa_command(stack);
	ft_printf("%wpa\n", stack->fd);
}

void	sort_int_4(t_stack_m *stack)
{
	common_for_4(stack);
	if (stack->stack_a.id_index[0] == 1)
		sa_comm(stack);
	else if (stack->stack_a.id_index[0] == 2)
	{
		sara_comm(stack);
		sarra_comm(stack);
	}
	else if (stack->stack_a.id_index[0] == 3)
		ra_comm(stack);
}
