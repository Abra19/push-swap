/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/18 22:19:43 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack *stack, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		stack->id_index[i] = size - 1;
		i++;
	}
}

void	count_id_index(t_stack *stack, int size)
{
	int		i;
	int		j;

	i = 0;
	if (size > 1)
	{
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				if (stack->arr[i] < stack->arr[j])
					stack->id_index[i] -= 1;
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		stack->sort_par += ft_abs(i - stack->id_index[i]);
		i++;
	}
}

void	init_stacks(t_stack_m *stack)
{
	ft_bzero(stack, sizeof(t_stack_m));
	ft_bzero(&stack->stack_a, sizeof(t_stack));
	ft_bzero(&stack->stack_b, sizeof(t_stack));
	stack->fd = 1;
	stack->num_comm = 1;
}

int		init_stack(t_stack *stack)
{
	if ((stack->arr = create_intarr(stack->size)) == 0)
		return (0);
	if ((stack->subarray = create_intarr(stack->size)) == 0)
		return (0);
	return (1);
}

int		init_i(t_stack_m *stack)
{
	int		i;

	i = 1;
	if (stack->onearg == 1)
		i = 2;
	if (stack->twoarg == 1)
		i = 3;
	return (i);
}
