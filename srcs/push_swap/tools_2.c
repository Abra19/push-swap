/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 02:01:44 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_four_int(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	else if (b <= a && b <= c && b <= d)
		return (b);
	else if (c <= a && c <= b && c <= d)
		return (c);
	else
		return (d);
}

int		min_int_array(int *array, int size)
{
	int		min;
	int		i;

	i = 1;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (array[i] == min)
			break ;
		i++;
	}
	return (i);
}

int		max_int_array(int *array, int size)
{
	int		max;
	int		i;

	i = 1;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

void	make_max_length_arr(t_stack_m *stack)
{
	int		i;

	i = 0;
	while (i < stack->stack_a.size)
	{
		if (stack->stack_a.subarray[i] == 0)
		{
			stack->num_comm++;
			pb_command(stack);
			ft_printf("%wpb\n", stack->fd);
		}
		else
		{
			if (stack->stack_a.size - stack->shift > stack->stack_a.subsize)
				ra_comm(stack);
		}
		i++;
	}
}
