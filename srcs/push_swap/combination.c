/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/20 19:43:32 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	combination_1(t_stack_m *stack)
{
	if ((stack->stack_a.id_index[0] == 0 && stack->stack_a.id_index[1] == 1) ||\
	(stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 0) ||\
	(stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 2) ||\
	(stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 2) ||\
	(stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 4) ||\
	(stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 0) ||\
	(stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 3))
		stack->combination = 1;
	if ((stack->stack_a.id_index[0] == 0 && stack->stack_a.id_index[1] == 2) ||\
	(stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 3) ||\
	(stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 0) ||\
	(stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 1) ||\
	(stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 3) ||\
	(stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 1))
		stack->combination = 2;
	if ((stack->stack_a.id_index[0] == 0 && stack->stack_a.id_index[1] == 3) ||\
	(stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 0) ||
	(stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 2))
		stack->combination = 3;
	if ((stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 4) ||\
	(stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 1))
		stack->combination = 4;
	if ((stack->stack_a.id_index[0] == 0 && stack->stack_a.id_index[1] == 4) ||\
	(stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 4))
		stack->combination = 5;
}

void	combination_2(t_stack_m *stack)
{
	if ((stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 2) ||\
	(stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 0) ||\
	(stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 3))
		stack->comb_1 = 1;
	if ((stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 2) ||\
	(stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 2))
		stack->comb_2 = 1;
	if ((stack->stack_a.id_index[0] == 3 && stack->stack_a.id_index[1] == 4) ||\
	(stack->stack_a.id_index[0] == 4 && stack->stack_a.id_index[1] == 3))
		stack->comb_2 = 2;
	if ((stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 3) ||\
	(stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 3))
		stack->comb_1 = 2;
	if ((stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 0) ||\
	(stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 1))
		stack->comb_1 = 3;
	if (stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 3)
		stack->comb_3 = 3;
	if ((stack->stack_a.id_index[0] == 2 && stack->stack_a.id_index[1] == 1) ||\
	stack->comb_3 == 3)
		stack->comb_2 = 4;
	if ((stack->stack_a.id_index[0] == 1 && stack->stack_a.id_index[1] == 3) ||\
	stack->comb_3 == 3)
		stack->comb_3 = 5;
}

void	combination(t_stack_m *stack)
{
	combination_1(stack);
	combination_2(stack);
}
