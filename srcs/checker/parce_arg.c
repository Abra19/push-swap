/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:25:42 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		parce_args(t_stack_m *stack, int argc, char **argv)
{
	if ((stack->stack_a.size = count_numbers(argc, argv, stack)) == -1 ||
    (stack->stack_a.size = count_numbers(argc, argv, stack)) == 0) /////// elim arg "  ""
		return (0);
	stack->stack_b.size = stack->stack_a.size;
	if (init_stack(&stack->stack_a) == 0)
		return (0);
	if (init_stack(&stack->stack_b) == 0)
	{
		free(stack->stack_a.arr);
		return (0);
	}
	if (make_stack(argc, argv, stack) == 0)
	{
		free_stacks(stack);
		return (0);
	}
	if (check_double(&stack->stack_a) == 0)
	{
		free_stacks(stack);
		return (0);
	}
	return (1);
}
