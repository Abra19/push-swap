/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/20 21:48:05 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	common_for_5(t_stack_m *stack)
{
	stack->num_comm++;
	pb_command(stack);
	ft_printf("%wpb\n", stack->fd);
	stack->num_comm++;
	pb_command(stack);
	ft_printf("%wpb\n", stack->fd);
	sort_int_3(stack);
	stack->combination = 0;
	stack->comb_1 = 0;
	stack->comb_3 = 0;
	stack->comb_3 = 0;
	combination(stack);
}

void	sort_int_5_comb_1(t_stack_m *stack)
{
	if (stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 2)
		rra_comm(stack);
	if (stack->comb_1 == 1)
		sb_comm(stack);
	if (stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 2)
		ra_comm(stack);
	papa_comm(stack);
	if (stack->comb_2 == 1)
	{
		rra_comm(stack);
		if (stack->stack_a.id_index[0] == 3)
			rra_comm(stack);
	}
	if (stack->comb_2 == 2)
		rara_comm(stack);
	if (stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 0)
		ra_comm(stack);
}

void	sort_int_5_comb_2(t_stack_m *stack)
{
	if (stack->comb_1 == 2)
		ra_comm(stack);
	if (stack->comb_1 == 3)
		sb_comm(stack);
	pasapa_comm(stack);
	if (stack->comb_2 == 4)
		sa_comm(stack);
	if (stack->comb_3 == 5)
		rra_comm(stack);
	if (stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 1)
		ra_comm(stack);
}

void	sort_int_5_comb_3(t_stack_m *stack)
{
	if (stack->stack_a.id_index[0] == 3)
		pa_comm(stack);
	rraparara_comm(stack);
	if (stack->stack_a.id_index[0] == 0 || stack->stack_a.id_index[0] == 4)
		pa_comm(stack);
	if (stack->stack_a.id_index[0] == 4)
		ra_comm(stack);
}

void	sort_int_5(t_stack_m *stack)
{
	common_for_5(stack);
	if (stack->combination == 1)
		sort_int_5_comb_1(stack);
	if (stack->combination == 2)
		sort_int_5_comb_2(stack);
	if (stack->combination == 3)
		sort_int_5_comb_3(stack);
	if (stack->combination == 4)
	{
		if (stack->stack_a.id_index[0] == 3)
			pasarra_comm(stack);
		parara_comm(stack);
		if (stack->stack_a.id_index[0] == 2)
			pasarra_comm(stack);
	}
	if (stack->combination == 5)
	{
		parapa_comm(stack);
		if (stack->stack_a.id_index[0] == 1)
			sa_comm(stack);
	}
}
